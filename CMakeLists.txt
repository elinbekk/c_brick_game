cmake_minimum_required(VERSION 3.26)
project(C7_BrickGame_v1_0_1 C)

set(CMAKE_C_STANDARD 11)

find_package(Curses)

include_directories(${CURSES_INCLUDE_DIR})

set(BACKEND_SOURCES
        src/brick_game/tetris/backend/fsm_matrix.c
        src/brick_game/tetris/inc/constants.h
        src/brick_game/tetris/inc/structs.h
        src/brick_game/tetris/inc/tetris.h
        src/brick_game/tetris/backend/parameters/parameters.c
        src/brick_game/tetris/inc/parameters.h
        src/brick_game/tetris/backend/game_state/game_state.c
        src/brick_game/tetris/inc/game_state.h
        src/brick_game/tetris/backend/player/player.c
        src/brick_game/tetris/inc/player.h
        src/brick_game/tetris/inc/macros.h
        src/brick_game/tetris/backend/tetramino/tetramino.c
        src/brick_game/tetris/inc/tetramino.h
        src/brick_game/tetris/backend/cell/cell.c
        src/brick_game/tetris/inc/cell.h
        src/brick_game/tetris/backend/board/board.c
        src/brick_game/tetris/inc/board.h
)

set(FRONTEND_SOURCES
        src/brick_game/tetris/tetris.c
        src/brick_game/tetris/inc/fsm_matrix.h
)

add_executable(C7_BrickGame_v1_0_1
        ${BACKEND_SOURCES}
        ${FRONTEND_SOURCES}
)


set(TEST_SOURCES
        tests/tetris_tests/test.c
        tests/tetris_tests/fsm_suite.c
        tests/tetris_tests/rename_suite.c
        tests/tetris_tests/game_state_suite.c
        tests/tetris_tests/board_suite.c
        tests/tetris_tests/player_suite.c
        tests/tetris_tests/collision_suite.c

)

add_executable(tests
        ${TEST_SOURCES}
        ${BACKEND_SOURCES}
)
add_executable(manual_test
        tests/tetris_tests/manual_test.c
        ${BACKEND_SOURCES}
)

target_link_libraries(C7_BrickGame_v1_0_1 ${CURSES_LIBRARIES})
target_link_libraries(C7_BrickGame_v1_0_1 -lcheck)
target_link_libraries(tests -lcheck)
