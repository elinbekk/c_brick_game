//
// Created by Mildred Marcela on 24.04.2024.
//

#ifndef C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_GAME_STATE_GAME_STATE_H_
#define C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_GAME_STATE_GAME_STATE_H_

#include "structs.h"

void SetGameState(GameState *p_game_state, GameState new_game_state);
GameState GetGameState(const GameState *p_game_state);


#endif //C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_GAME_STATE_GAME_STATE_H_
