#include "../../inc/board.h"
#include "../../inc/cell.h"
#include "stdio.h"

//todo: maybe rename
void SetGameBoard(GameBoard *p_board) {
  p_board->width_ = BOARD_WIDTH;
  p_board->height_ = BOARD_HEIGHT;
  for (int i = 0; i < p_board->width_; i++) {
    for (int j = 0; j < p_board->height_; j++) {
      SetCell(&p_board->cells_[i][j]);
    }
  }
}

int IsLineFull(GameBoard *p_board, int line_index) {
  for (int i = 0; i < p_board->width_; i++) {
    if (p_board->cells_[line_index][i].symbol_ == 0) {
      return 0;
    }
  }
  return 1;
}

int GetFullLinesCount(GameBoard *p_board) {
  int count = 0;
  for (int i = 0; i < p_board->height_; i++) {
    if (IsLineFull(p_board, i)) {
      count += 1;
    }
  }
  return count;
}

void DeleteLine(GameBoard *p_board, int line_index) {
  for (int i = 0; i < p_board->width_; i++) {
    SetCell(&p_board->cells_[line_index][i]);
  }
}

void ShiftLineDown(GameBoard *p_board, int line_index) {
  if (line_index == 0) {
    for (int i = 0; i < p_board->width_; i++) {
      SetCell(&p_board->cells_[line_index][i]);
    }
  } else {
    for (int i = line_index; i > 0; i--) {
      for (int j = 0; j < p_board->width_; j++) {
        p_board->cells_[i][j] = p_board->cells_[line_index - 1][p_board->width_];
      }
    }
  }
}

void ShiftDownBoard(GameBoard *p_board) {
  for (int i = 0; i < p_board->height_; i++) {
    ShiftLineDown(p_board, i);
  }
}

void PrintBoard(const GameBoard game_board ){
  for (int i = 0; i < game_board.height_; ++i) {
    for (int j = 0; j < game_board.width_; ++j) {
      printf("%c ", 'a' + game_board.cells_[i][j].symbol_);
    }
    printf("\n");
  }
  printf("\n\n\n");
}