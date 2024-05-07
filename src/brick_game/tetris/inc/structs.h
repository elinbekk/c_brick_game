#ifndef FSM_H
#define FSM_H

#include "constants.h"
#include "structs.h"
#include "tetramino.h"

typedef enum {
  kGameStateStart = 0,
  kGameStateSpawn = 1,
  kGameStateMoving = 2,
  kGameStateCollide = 3,
  kGameStatePause = 4,
  kGameStateGameOver = 5,
  kGameStateExitState = 6
} GameState;

typedef enum {
  kSignalRotate = 0,
  kSignalMoveDown = 1,
  kSignalMoveRight = 2,
  kSignalMoveLeft = 3,
  kSignalEscape = 4,
  kSignalEnter = 5,
  kSignalPause = 6,
  kSignalNone = 7,
} Signal;


typedef enum {
  tetraminoI = 0,
  tetraminoJ = 1,
  tetraminoL = 2,
  tetraminoO = 3,
  tetraminoT = 4,
  tetraminoZ = 5,
  tetraminoS = 6
} TetraminoType;

//todo: style
typedef enum {
  RotationType0 = 0,
  RotationType1 = 1,
  RotationType2 = 2,
  RotationType3 = 3
} TetraminoRotationType;

typedef struct {
  int x_;
  int y_;
} Position;

typedef struct{ //add color
  int symbol_;
}Cell;

typedef struct {
  Cell board_[PLAYER_BOARD_SIZE][PLAYER_BOARD_SIZE];
}PlayerBoard;

typedef struct {
  Position position_;
  TetraminoType tetramino_type_;
  TetraminoRotationType tetramino_rotation_type_;
  PlayerBoard player_board_;
} Player;

typedef struct {
  int height_;
  int width_;
  Cell cells_ [BOARD_HEIGHT][BOARD_WIDTH];
} GameBoard;

typedef struct{
  int score_;
  char name_[30];
} Record;

typedef struct {
  GameState *p_game_state_;
  Player *p_current_player_;
  Player *p_next_player_;
  GameBoard *p_game_board_;
} Parameters;




#endif
