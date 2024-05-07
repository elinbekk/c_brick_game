#ifndef C7_BRICKGAME_V1_0_1_TEST_H
#define C7_BRICKGAME_V1_0_1_TEST_H

#include <check.h>
#include "../../src/brick_game/tetris/inc/tetris.h"

Suite *GetRenameSuite();
Suite *GetFsmSuite();
Suite *GetPlayerSuite();
Suite *GetGameStateSuite();
Suite *GetBoardSuite();
Suite *GetCollisionSuite();
#endif //C7_BRICKGAME_V1_0_1_TEST_H
