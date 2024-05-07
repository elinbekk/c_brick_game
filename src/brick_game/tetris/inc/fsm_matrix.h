#ifndef C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_FSM_MATRIX_H_
#define C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_FSM_MATRIX_H_

#include "parameters.h"
#include <stddef.h>

typedef GameState (*ActionCallback)(Parameters *parameters);

GameState StartAction(Parameters *parameters);

GameState SpawnAction(Parameters *parameters);

GameState RotateAction(Parameters *parameters);

GameState MoveDownAction(Parameters *parameters);

GameState MoveRightAction(Parameters *parameters);

GameState MoveLeftAction(Parameters *parameters);

GameState PauseAction(Parameters *parameters);

GameState CollideAction(Parameters *parameters);

GameState GameOverAction(Parameters *parameters);

GameState ExitAction(Parameters *parameters);

Signal GetSignal(int user_input);

void UpdateCurrentStateBySignal(Parameters *p_parameters, Signal signal);


#endif //C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_FSM_MATRIX_H_
