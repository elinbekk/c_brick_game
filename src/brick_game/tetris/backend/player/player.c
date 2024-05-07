#include "../../inc/player.h"
#include "../../inc/cell.h"

void SpawnPlayerOnBoard(GameBoard *game_board, Player *p_player) {
  p_player->position_.x_ = game_board->width_ / 2 - 2;
  p_player->position_.y_ = 0;
}

void InitPlayer(Player *p_player) {
  int tetramino_type = GenerateTetraminoType();
  int rotation_type = GenerateRotationType();
  InitPlayerBoard(&p_player->player_board_);
  SetTetraminoInPlayerBoard(&p_player->player_board_, tetramino_type, rotation_type);
}

Player GetPlayer(Player *p_player) {
  return *p_player;
}
void SetPlayer(Player *p_player, const Player new_player) {
  *p_player = new_player;
}

void SetPlayerPosition(Player *p_player, Position position) {
  p_player->position_ = position;
}

Position GetPlayerPosition(Player *p_player) {
  return p_player->position_;
}

void SetPlayerTetraminoType(Player *p_player, TetraminoType tetramino_type) {
  p_player->tetramino_type_ = tetramino_type;
  SetTetraminoInPlayerBoard(&p_player->player_board_, p_player->tetramino_type_,
                            p_player->tetramino_rotation_type_);
}

void SetPlayerRotationType(Player *p_player, TetraminoRotationType rotation_type) {
  p_player->tetramino_rotation_type_ = rotation_type;
  SetTetraminoInPlayerBoard(&p_player->player_board_, p_player->tetramino_type_,
                            p_player->tetramino_rotation_type_);
}

void InitPlayerBoard(PlayerBoard *p_player_board) {
  for (int i = 0; i < PLAYER_BOARD_SIZE; i++) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; j++) {
      SetCell(&p_player_board->board_[i][j]);
    }
  }
}

void SetTetraminoInPlayerBoard(PlayerBoard *player_board, TetraminoType tetramino_type,
                               TetraminoRotationType rotation_type) {
  int tetramino_mask = 0b1000000000000000;
  for (int i = 0; i < PLAYER_BOARD_SIZE; i++) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; j++) {
      int tetramino = tetraminos_masks[tetramino_type][rotation_type];
      if (tetramino & tetramino_mask) {
        player_board->board_[i][j].symbol_ = 1;
      } else {
        player_board->board_[i][j].symbol_ = 0;
      }
      tetramino_mask >>= 1;
    }
  }
}

int isCollision(Player *player, GameBoard *game_board) {
  int isCollision = 0;
  for (int i = 0; i < PLAYER_BOARD_SIZE; i++) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; j++) {
      if (player->player_board_.board_[i][j].symbol_ == 1) {
        int new_index_x = player->position_.x_ + j;
        int new_index_y = player->position_.y_ + i;
        if (game_board->cells_[new_index_x][new_index_y].symbol_ == 1) {
          isCollision = 1;
        }
        //todo: check comparison operators
        if (new_index_x >= game_board->width_ || new_index_x <= 0 || new_index_y > game_board->height_) {
          isCollision = 1;
        }
      }
    }
  }
  return isCollision;
}

void ShiftPlayerRight(Player *player) {
  player->position_.x_++;
}

void ShiftPlayerLeft(Player *player) {
  player->position_.x_--;
}
void ShiftPlayerDown(Player *player) {
  player->position_.y_++;
}

void ShiftPlayerUp(Player *player) {
  player->position_.y_--;
}

void RotatePlayer(Player *player) {
  PlayerBoard player_board = player->player_board_;
  TetraminoType tetramino_type = player->tetramino_type_;
  TetraminoRotationType rotation_type = GetNextRotationType(player->tetramino_rotation_type_);
  SetTetraminoInPlayerBoard(&player_board, tetramino_type, rotation_type);
}

void CopyPlayer(const Player *src, Player* dest) {
  dest->position_ = src->position_;
  dest->player_board_ = src->player_board_;
  dest->tetramino_type_ = src->tetramino_type_;
  dest->tetramino_rotation_type_ = src->tetramino_rotation_type_;
}

TetraminoRotationType GetNextRotationType(TetraminoRotationType rotation_type) {
  TetraminoRotationType next_rotation = RotationType0;
  if (rotation_type == RotationType0) {
    next_rotation = RotationType1;
  } else if (rotation_type == RotationType1) {
    next_rotation = RotationType2;
  } else if (rotation_type == RotationType2) {
    next_rotation = RotationType3;
  } else if (rotation_type == RotationType3) {
    next_rotation = RotationType0;
  }
  return next_rotation;
}

void AttachePlayer(const Player *player, GameBoard *game_board) {
  for (int local_index_y = 0; local_index_y < PLAYER_BOARD_SIZE; local_index_y++) {
    for (int local_index_x = 0; local_index_x < PLAYER_BOARD_SIZE; local_index_x++) {
      if (player->player_board_.board_[local_index_y][local_index_x].symbol_ == 1) {
        int global_index_y = player->position_.y_ + local_index_y;
        int global_index_x = player->position_.x_ + local_index_x;
        if (global_index_y >= game_board->height_){
          global_index_y = game_board->height_ - 1;
        }
        if (global_index_x >= game_board->width_){
          global_index_x = game_board->width_ - 1;
        }
        game_board->cells_[global_index_y][global_index_x].symbol_ = player->player_board_.board_[local_index_y][local_index_x].symbol_;
      }
    }
  }
}

void UpdateCurrentPlayerToTheNext(Player *current, Player *next){

}
