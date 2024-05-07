#include <stdbool.h>
#include <ncurses.h>
#include "inc/tetris.h"
#include "inc/fsm_matrix.h"

void GameLoop();

/*int main(void) {
//    WIN_INIT(50);

  setlocale(LC_ALL, "");
  GameLoop();
  return SUCCESS;
}*/

void GameLoop() {
  Parameters parameters = {0};
  GameBoard game_board= {0};
  GameState game_state = kGameStateStart;
  Player current_player = {0};
  Player next_player = {0};

  parameters.p_game_board_ = &game_board;
  parameters.p_game_state_ = &game_state;
  parameters.p_current_player_ = &current_player;
  parameters.p_next_player_ = &next_player;

  bool break_flag = TRUE;
  int ascii_signal = 0;

  while (break_flag) {
    if (game_state == kGameStateGameOver || game_state == kGameStateExitState){
      break_flag = FALSE;
    }
    Signal signal = GetSignal(ascii_signal);

    UpdateCurrentStateBySignal(&parameters, signal);
    //ascii_signal = getch();
  }
}

/*
void printGame(Parameters *parameters){
  Player *player = parameters->p_current_player_;
  GameBoard *game_board = parameters->p_game_board_;
  char sym = 0;
  for(int i = 0; i < game_board->height_; i++){
    for(int j =0 ; j < game_board->width_; j++){
      if(game_board->cells_[i][j].symbol_ == 1){
        sym = '*';
      }else{
        int global_x = i - player->position_.x_;
        int global_y = j - player->position_.y_;
        if(global_x >= 0 && global_x < PLAYER_BOARD_SIZE && global_y >= 0 && global_y < PLAYER_BOARD_SIZE){
          if(player->player_board_.board_[i][j].symbol_ == 1){
            sym = '*';
          }
        }
      }
      printf("%c", sym);
    }
  }
  fflush(stdout);
}*/
