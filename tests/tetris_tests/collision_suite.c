#include <printf.h>
#include "test.h"

START_TEST(right_side_collision_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  ShiftPlayerDown(&player);
  for (int i = 0; i < game_board.width_ - PLAYER_BOARD_SIZE; i++) {
    ShiftPlayerRight(&player);
  }
  int res = isCollision(&player, &game_board);
  int orig = 1;
  ck_assert_int_eq(res, orig);
}

START_TEST(left_side_collision_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  ShiftPlayerDown(&player);
  for (int i = 0; i < game_board.width_ - PLAYER_BOARD_SIZE; i++) {
    ShiftPlayerLeft(&player);
  }
  int res = isCollision(&player, &game_board);
  int orig = 1;
  ck_assert_int_eq(res, orig);
}

START_TEST(down_side_collision_test) {
  Player player = {0};
  InitPlayer(&player);
  GameBoard game_board = {0};
  SetGameBoard(&game_board);
  SpawnPlayerOnBoard(&game_board, &player);
  for (int i = 0; i < game_board.height_ - PLAYER_BOARD_SIZE; i++) {
    ShiftPlayerDown(&player);
  }
  printf("PLAYER POSITION: %d\n", player.position_.y_);
  int res = isCollision(&player, &game_board);
  int orig = 1;
  ck_assert_int_eq(res, orig);
}
END_TEST

Suite *GetCollisionSuite() {
  Suite *suite = suite_create("collision_suite");
  TCase *tc_case = tcase_create("collision_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, right_side_collision_test);
  tcase_add_test(tc_case, left_side_collision_test);
  tcase_add_test(tc_case, down_side_collision_test);
  return suite;
}