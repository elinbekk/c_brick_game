#include <printf.h>
#include "test.h"
#include "../../src/brick_game/tetris/inc/fsm_matrix.h"

START_TEST(fsm_suite_test_from_start_to_spawn) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);
  Signal signal = kSignalEnter;
  ck_assert_int_eq(*parameters.p_game_state_, kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);

  ck_assert_int_eq(*parameters.p_game_state_, kGameStateSpawn);
}

START_TEST(fsm_suite_test_from_spawn_to_moving) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters);
  InitParameters(&parameters);
  Signal signal = kSignalEnter;
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);
}

START_TEST(fsm_suite_test_from_moving_to_collide) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);
  Signal signal = kSignalEnter;
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);
  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);

  signal = kSignalMoveDown;
  for (int i = 0; i < parameters.p_game_board_->height_ - PLAYER_BOARD_SIZE; ++i) {
    UpdateCurrentStateBySignal(&parameters, signal);
    ck_assert_int_ne(GetGameState(parameters.p_game_state_), kGameStateCollide);
  }

  int collide_state_count = 0;

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    UpdateCurrentStateBySignal(&parameters, signal);
    if (GetGameState(parameters.p_game_state_) == kGameStateCollide) {
      collide_state_count++;
    }
  }

  ck_assert_int_eq(collide_state_count, 1);
}
END_TEST

START_TEST(fsm_suite_test_to_pause) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);
  Signal signal = kSignalEnter;
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);

  Signal signal2 = kSignalPause;
  UpdateCurrentStateBySignal(&parameters, signal2);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStatePause);
}
END_TEST

START_TEST(fsm_suite_test_from_pause_to_moving) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);

  Signal signal = kSignalEnter;
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);

  Signal signal2 = kSignalPause;
  UpdateCurrentStateBySignal(&parameters, signal2);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStatePause);

  UpdateCurrentStateBySignal(&parameters, signal2);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);
}
END_TEST

START_TEST(fsm_suite_test_to_exit) {
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);

  Signal signal = kSignalEnter;
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);

  UpdateCurrentStateBySignal(&parameters, signal);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);

  Signal signal2 = kSignalEscape;
  UpdateCurrentStateBySignal(&parameters, signal2);
  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateExitState);
}
END_TEST

Suite *GetFsmSuite() {
  Suite *suite = suite_create("fsm_suite");
  TCase *tc_case = tcase_create("fsm_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, fsm_suite_test_from_start_to_spawn);
  tcase_add_test(tc_case, fsm_suite_test_from_spawn_to_moving);
  tcase_add_test(tc_case, fsm_suite_test_from_moving_to_collide);
  tcase_add_test(tc_case, fsm_suite_test_to_pause);
  tcase_add_test(tc_case, fsm_suite_test_from_pause_to_moving);
  tcase_add_test(tc_case, fsm_suite_test_to_exit);
  //tcase_add_test(tc_case, fsm_suite_test_to_game_over);
  return suite;
}

