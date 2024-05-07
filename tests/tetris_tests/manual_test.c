#include "../../src/brick_game/tetris/inc/tetris.h"

int main(){
  Parameters parameters = {0};
  INIT_PARAMETERS_FIELDS(parameters)
  InitParameters(&parameters);
  Signal signal = kSignalEnter;
//  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateStart);

  UpdateCurrentStateBySignal(&parameters, signal);
//  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateSpawn);
  UpdateCurrentStateBySignal(&parameters, signal);
//  ck_assert_int_eq(GetGameState(parameters.p_game_state_), kGameStateMoving);

  signal = kSignalMoveDown;
  for (int i = 0; i < parameters.p_game_board_->height_ - PLAYER_BOARD_SIZE; ++i) {
    UpdateCurrentStateBySignal(&parameters, signal);
//    ck_assert_int_ne(GetGameState(parameters.p_game_state_), kGameStateCollide);
  }

  int collide_state_count = 0;

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    UpdateCurrentStateBySignal(&parameters, signal);
    if (GetGameState(parameters.p_game_state_) == kGameStateCollide) {
      collide_state_count++;
    }
  }

//  ck_assert_int_gt(collide_state_count, 0);
}