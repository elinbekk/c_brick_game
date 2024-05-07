#include <printf.h>
#include <stdlib.h>
#include "test.h"

START_TEST(player_init_test) {
  Player player = {0};
}

START_TEST(player_spawn_test) {
  Player player = {0};
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  int x_start = game_board.width_ / 2 - 2;
  int y_start = 0;
  SpawnPlayerOnBoard(&game_board, &player);
  ck_assert_int_eq(y_start, player.position_.y_);
  ck_assert_int_eq(x_start, player.position_.x_);
}

START_TEST(player_down_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  int dest = 1;
  ShiftPlayerDown(&player);
  ck_assert_int_eq(dest, player.position_.y_);
}

START_TEST(player_right_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  int dest_x = 4;
  ShiftPlayerRight(&player);
  ck_assert_int_eq(dest_x, player.position_.x_);
}

START_TEST(player_left_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  int dest_x = 2;
  ShiftPlayerLeft(&player);
  ck_assert_int_eq(dest_x, player.position_.x_);
}

START_TEST(player_up_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  int dest_x = 0;
  ShiftPlayerDown(&player);
  ShiftPlayerUp(&player);
  ck_assert_int_eq(dest_x, player.position_.y_);
}

START_TEST(player_rotate_test1) {
  TetraminoRotationType rotation_type = RotationType0;
  TetraminoRotationType result_rotation = GetNextRotationType(rotation_type);
  TetraminoRotationType orig_rotation = RotationType1;
  ck_assert_int_eq(orig_rotation, result_rotation);
}

START_TEST(player_rotate_test2) {
  TetraminoRotationType rotation_type = RotationType1;
  TetraminoRotationType result_rotation = GetNextRotationType(rotation_type);
  TetraminoRotationType orig_rotation = RotationType2;
  ck_assert_int_eq(orig_rotation, result_rotation);
}

START_TEST(player_rotate_test3) {
  TetraminoRotationType rotation_type = RotationType2;
  TetraminoRotationType result_rotation = GetNextRotationType(rotation_type);
  TetraminoRotationType orig_rotation = RotationType3;
  ck_assert_int_eq(orig_rotation, result_rotation);
}

START_TEST(player_rotate_test4) {
  TetraminoRotationType rotation_type = RotationType3;
  TetraminoRotationType result_rotation = GetNextRotationType(rotation_type);
  TetraminoRotationType orig_rotation = RotationType0;
  ck_assert_int_eq(orig_rotation, result_rotation);
}

START_TEST(tetramino_in_playerboard_setting_test) {
  PlayerBoard player_board = {0};
  TetraminoType tetramino_type = tetraminoI;
  TetraminoRotationType rotation_type = RotationType0;
  PlayerBoard result = {0};
  SetTetraminoInPlayerBoard(&player_board, tetramino_type, rotation_type);
  result.board_[0][0].symbol_ = 0;
  result.board_[0][1].symbol_ = 1;
  result.board_[0][2].symbol_ = 0;
  result.board_[0][3].symbol_ = 0;
  result.board_[1][0].symbol_ = 0;
  result.board_[1][1].symbol_ = 1;
  result.board_[1][2].symbol_ = 0;
  result.board_[1][3].symbol_ = 0;
  result.board_[2][0].symbol_ = 0;
  result.board_[2][1].symbol_ = 1;
  result.board_[2][2].symbol_ = 0;
  result.board_[2][3].symbol_ = 0;
  result.board_[3][0].symbol_ = 0;
  result.board_[3][1].symbol_ = 1;
  result.board_[3][2].symbol_ = 0;
  result.board_[3][3].symbol_ = 0;
  for (int i = 0; i < PLAYER_BOARD_SIZE; i++) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; j++) {
      ck_assert_int_eq(player_board.board_[i][j].symbol_, result.board_[i][j].symbol_);
    }
  }
}

#include "time.h"

START_TEST(player_attache_test) {
  Player player = {0};
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  AttachePlayer(&player, &game_board);
  //PrintBoard(game_board);
  for (int local_position_x = 0; local_position_x < PLAYER_BOARD_SIZE; ++local_position_x) {
    for (int local_position_y = 0; local_position_y < PLAYER_BOARD_SIZE; ++local_position_y) {

      const int global_position_x = player.position_.x_ + local_position_x;
      const int global_position_y = player.position_.y_ + local_position_y;
      ck_assert_int_eq(game_board.cells_[global_position_y][global_position_x].symbol_,
                       player.player_board_.board_[local_position_y][local_position_x].symbol_);
    }
  }

}

END_TEST

Suite *GetPlayerSuite() {
  Suite *suite = suite_create("player_suite");
  TCase *tc_case = tcase_create("player_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, player_init_test);
  tcase_add_test(tc_case, player_spawn_test);
  tcase_add_test(tc_case, player_down_test);
  tcase_add_test(tc_case, player_right_test);
  tcase_add_test(tc_case, player_left_test);
  tcase_add_test(tc_case, player_up_test);
  tcase_add_test(tc_case, player_rotate_test1);
  tcase_add_test(tc_case, player_rotate_test2);
  tcase_add_test(tc_case, player_rotate_test3);
  tcase_add_test(tc_case, player_rotate_test4);
  tcase_add_test(tc_case, tetramino_in_playerboard_setting_test);
  tcase_add_test(tc_case, player_attache_test);
  return suite;
}

