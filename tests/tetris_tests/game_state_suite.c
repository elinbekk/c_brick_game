#include "test.h"

START_TEST(game_state_setter) {
  GameState game_state = {0};
  SetGameState(&game_state, kGameStateGameOver);
  ck_assert_int_eq(game_state, kGameStateGameOver);
}
START_TEST(game_state_getter) {
  GameState game_state = {0};
  SetGameState(&game_state, kGameStateGameOver);
  ck_assert_int_eq(game_state, kGameStateGameOver);

  GameState state = GetGameState(&game_state);
  ck_assert_int_eq(state, kGameStateGameOver);
}

Suite *GetGameStateSuite() {
  Suite *suite = suite_create("game_state_suite");
  TCase *tc_case = tcase_create("game_state_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, game_state_setter);
  tcase_add_test(tc_case, game_state_getter);
  return suite;
}

