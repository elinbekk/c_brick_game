#ifndef C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_INC_MACROS_H_
#define C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_INC_MACROS_H_

#define INIT_PARAMETERS_FIELDS(PARAMETERS) \
GameBoard game_board= {0}; \
GameState game_state = {0}; \
Player current_player = {0}; \
Player next_player = {0}; \
PARAMETERS.p_game_board_ = &game_board; \
PARAMETERS.p_game_state_ = &game_state; \
PARAMETERS.p_current_player_ = &current_player; \
PARAMETERS.p_next_player_ = &next_player;

#endif //C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_INC_MACROS_H_
