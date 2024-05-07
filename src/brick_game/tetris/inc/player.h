#ifndef C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_PLAYER_PLAYER_H_
#define C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_PLAYER_PLAYER_H_

#include "structs.h"
#include "tetramino.h"

void SetPlayer(Player *p_player, Player);
Player GetPlayer(Player *p_player);
void SetPlayerPosition(Player *p_player, Position position);
Position GetPlayerPosition(Player *p_player);
void InitPlayerBoard(PlayerBoard *p_player_board);
void SpawnPlayerOnBoard(GameBoard *game_board, Player *p_player);
void SetTetraminoInPlayerBoard(PlayerBoard *player_board,
                               TetraminoType tetramino_type,
                               TetraminoRotationType rotation_type);

int isCollision(Player *player, GameBoard *game_board);
void ShiftPlayerRight(Player *player);
void ShiftPlayerLeft(Player *player);
void ShiftPlayerDown(Player *player);
void ShiftPlayerUp(Player *player);
void RotatePlayer(Player *player);
void CopyPlayer(const Player *src, Player* dest);
void AttachePlayer(const Player *player, GameBoard *game_board);
void InitPlayer(Player *p_player);
void UpdateCurrentPlayerToTheNext(Player *current, Player *next);
TetraminoRotationType GetNextRotationType(TetraminoRotationType rotation_type);

#endif //C7_BRICKGAME_V1_0_1_SRC_BRICK_GAME_TETRIS_SRC_BACKEND_PLAYER_PLAYER_H_
