#include "../../inc/parameters.h"
#include "../../inc/game_state.h"
#include "../../inc/board.h"
#include "../../inc/player.h"

void InitParameters(Parameters *p_parameters){
  SetGameBoard(p_parameters->p_game_board_);
  InitPlayer(p_parameters->p_current_player_);
  InitPlayer(p_parameters->p_next_player_);
  SpawnPlayerOnBoard(p_parameters->p_game_board_, p_parameters->p_current_player_);
}



