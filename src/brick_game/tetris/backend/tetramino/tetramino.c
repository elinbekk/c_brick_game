#include <stdlib.h>
#include "../../inc/tetramino.h"

int GenerateTetraminoType(){
  int tetramino_type = rand() % TETRAMINOS_COUNT;
  return tetramino_type;
}

int GenerateRotationType(){
  int rotation_type = rand() % 4;
  return rotation_type;
}
