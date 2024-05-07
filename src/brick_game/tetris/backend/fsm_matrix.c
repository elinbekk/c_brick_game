#include "../inc/fsm_matrix.h"
#include "../inc/game_state.h"
#include "../inc/tetris.h"

static ActionCallback fsm_table[7][8] = {
    {NULL, NULL, NULL, NULL, ExitAction, StartAction, NULL, NULL},     //start state
    {SpawnAction, SpawnAction, SpawnAction, SpawnAction, SpawnAction, SpawnAction, SpawnAction, NULL},   //Spawn state
    {RotateAction, MoveDownAction, MoveRightAction, MoveLeftAction, ExitAction, NULL, PauseAction, NULL}, //move state
    {CollideAction, CollideAction, CollideAction, CollideAction, CollideAction, CollideAction,
     CollideAction}, //collide state
    {NULL, NULL, NULL, NULL, NULL, NULL, PauseAction, NULL}, //pause state
    {GameOverAction, GameOverAction, GameOverAction, GameOverAction, GameOverAction, StartAction, GameOverAction,
     GameOverAction}, // game over state
    {ExitAction, ExitAction, ExitAction, ExitAction, ExitAction, ExitAction, ExitAction} //exit state
};

Signal GetSignal(int user_input) {
  Signal signal = kSignalNone;
  if (user_input == KEY_UP) {
    signal = kSignalRotate;
  } else if (user_input == KEY_DOWN)
    signal = kSignalMoveDown;
  else if (user_input == KEY_LEFT)
    signal = kSignalMoveLeft;
  else if (user_input == KEY_RIGHT)
    signal = kSignalMoveRight;
  else if (user_input == ESCAPE)
    signal = kSignalEscape;
  else if (user_input == ENTER_KEY)
    signal = kSignalEnter;
  else if (user_input == KEY_PAUSE)
    signal = kSignalPause;
  return signal;
}

void UpdateCurrentStateBySignal(Parameters *p_parameters, Signal signal) {
  GameState state = GetGameState(p_parameters->p_game_state_);

  ActionCallback p_function = fsm_table[state][signal];

  if (p_function) {
    GameState new_state = p_function(p_parameters);
    SetGameState(p_parameters->p_game_state_, new_state);
  }
}

GameState StartAction(Parameters *parameters) {
  //todo: upload game info: record, level, score...............
  InitParameters(parameters);
  GameState new_state = kGameStateSpawn;
  return new_state;
}

GameState SpawnAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  CopyPlayer(parameters->p_next_player_, parameters->p_current_player_);
  InitPlayer(parameters->p_next_player_);

  //todo: test for correct handle of GameOver case
  Player copy_player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  ShiftPlayerDown(&copy_player);
  if (!isCollision(&copy_player, game_board)) {
    SetPlayer(parameters->p_current_player_, copy_player);
    new_state = kGameStateMoving;
  } else {
    new_state = kGameStateGameOver;
  }
  return new_state;
}

GameState CollideAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  //Player player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  AttachePlayer(parameters->p_current_player_, game_board);
  int full_lines_count = GetFullLinesCount(game_board);
  if (full_lines_count > 0) {
    for (int i = 0; i < game_board->height_; i++) {
      if (IsLineFull(game_board, i)) {
        DeleteLine(game_board, i);
      }
    }
    ShiftDownBoard(game_board);
  }
  new_state = kGameStateSpawn;
  return new_state;
}

GameState RotateAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  Player copy_player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  RotatePlayer(&copy_player);
  if (!isCollision(&copy_player, game_board)) {
    SetPlayer(parameters->p_current_player_, copy_player);
  }
  return new_state;
}

GameState MoveDownAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  Player copy_player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  ShiftPlayerDown(&copy_player);
  if (!isCollision(&copy_player, game_board)) {
    SetPlayer(parameters->p_current_player_, copy_player);
  } else {
    new_state = kGameStateCollide;
  }
  return new_state;
}

GameState MoveRightAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  Player copy_player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  ShiftPlayerRight(&copy_player);
  if (!isCollision(&copy_player, game_board)) {
    SetPlayer(parameters->p_current_player_, copy_player);
  }
  return new_state;
}

GameState MoveLeftAction(Parameters *parameters) {
  GameState new_state = GetGameState(parameters->p_game_state_);
  Player copy_player = GetPlayer(parameters->p_current_player_);
  GameBoard *game_board = parameters->p_game_board_;
  ShiftPlayerLeft(&copy_player);
  if (!isCollision(&copy_player, game_board)) {
    SetPlayer(parameters->p_current_player_, copy_player);
  }
  return new_state;
}

GameState PauseAction(Parameters *parameters) {
  GameState current_state = GetGameState(parameters->p_game_state_);
  GameState new_state = {0};
  if (current_state != kGameStatePause) {
    new_state = kGameStatePause;
  } else {
    new_state = kGameStateMoving;
  }
  return new_state;
}

GameState GameOverAction(Parameters *parameters) {
  //todo: save game info: record, level, score...............
  GameState new_state = GetGameState(parameters->p_game_state_);
  return new_state;
}

GameState ExitAction(Parameters *parameters) {
  //todo: save game info: record, level, score...............
  (void) parameters;
  GameState new_state = kGameStateExitState;
  return new_state;
}