#include "test.h"

START_TEST(board_initial_test) {
  GameBoard board = {0};
  SetGameBoard(&board);
  for(int i = 0; i < board.height_; i++){
    for(int j = 0; j < board.width_;j++){
      int value = board.cells_[i][j].symbol_;
      ck_assert_int_eq(value, 0);
    }
  }
}

START_TEST(board_line_is_full_test) {
  GameBoard board = {0};
  SetGameBoard(&board);
  int line_index = 5;
  for(int j = 0; j < board.width_;j++){
    board.cells_[line_index][j].symbol_ = 1;
  }
  int result = IsLineFull(&board, line_index);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(board_get_full_line_count_test) {
  GameBoard board = {0};
  SetGameBoard(&board);
  int line_index = 5;
  for(int j = 0; j < board.width_;j++){
    board.cells_[line_index][j].symbol_ = 1;
  }
  line_index += 2;
  for(int j = 0; j < board.width_;j++){
    board.cells_[line_index][j].symbol_ = 1;
  }
  int full_lines = 2;
  int result = GetFullLinesCount(&board);

  ck_assert_int_eq(full_lines, result);
}
END_TEST


START_TEST(board_line_is_deleted_test) {
  GameBoard board = {0};
  SetGameBoard(&board);
  int line_index = 7;
  for(int j = 0; j < board.width_;j++){
    board.cells_[line_index][j].symbol_ = 1;
  }

  DeleteLine(&board, line_index);
  for(int j = 0; j < board.width_;j++){
    int value = board.cells_[line_index][j].symbol_;
    ck_assert_int_eq(0, value);
  }
}
END_TEST

/***void ShiftLineDown(GameBoard *p_board, int line_index) {
  if(line_index == 0){
    for(int i = 0; i < p_board->width_; i++){
      SetCell(&p_board->cells_[line_index][i]);
    }
  }else{
    for (int i = line_index; i > 0; i--) {
      for (int j = 0; j < p_board->width_; j++){
        p_board->cells_[i][j] = p_board->cells_[line_index - 1][p_board->width_];
      }
    }
  }
}
*/
/*START_TEST(board_line_is_shifted_test1) {

}

START_TEST(board_line_is_shifted_test2) {

}*/
END_TEST

Suite *GetBoardSuite() {
  Suite *suite = suite_create("board_suite");
  TCase *tc_case = tcase_create("board_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, board_initial_test);
  tcase_add_test(tc_case, board_line_is_full_test);
  tcase_add_test(tc_case, board_line_is_deleted_test);
  tcase_add_test(tc_case, board_get_full_line_count_test);
//  tcase_add_test(tc_case, board_line_is_shifted_test1);
//  tcase_add_test(tc_case, board_line_is_shifted_test2);
  return suite;
}
