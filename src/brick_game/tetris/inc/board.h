#ifndef C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_
#define C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_

#include "structs.h"

void SetGameBoard(GameBoard *p_board);
int IsLineFull(GameBoard *p_board, int line_index);
int GetFullLinesCount(GameBoard *p_board);
void DeleteLine(GameBoard *p_board, int line_index);
void ShiftLineDown(GameBoard *p_board, int line_index);
void ShiftDownBoard(GameBoard *p_board);
void PrintBoard(const GameBoard game_board);

#endif //C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_
