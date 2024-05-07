#include "../../inc/game_state.h"

void SetGameState(GameState *p_game_state, GameState new_game_state){
  *p_game_state = new_game_state;
}
GameState GetGameState(const GameState *p_game_state){
  return *p_game_state;
}

