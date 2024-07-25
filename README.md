# BrickGame v1.0 aka Tetris

Implementing the Tetris game in the C programming language using FSM(Finite-state machine).

- The program was developed in C language of C11 standard using gcc compiler.
- For terminal interface used the `ncurses` library.
- The program library code located in the `src/brick_game/tetris` folder.
- The program interface code located in the `src/gui/cli` folder

### Tetris finite-state machine

![fsm](materials/Screenshot 2024-05-12 at 17.02.43.png)
This FSM has the following states:

- Start is the state in which the game waits for the player to press the ready to play button('Enter')
- Spawn (state the game enters when you create another block and choose the next block to SpawnAction)
- Moving (state with user input processing - rotating blocks/moving blocks horizontally)
- Collide
- Pause
- Exit
- Game over is a game over.

### Tetris game
- The following mechanics are in the game:
    - Rotation of tetraminoes;
    - Moving tetraminoes horizontally;
    - Acceleration of the tetramino's fall (when the button is pressed, the figure moves all the way down);
    - Display of the next tetramino;
    - Destruction of filled raws;
    - End of the game when the top border of the playing field is reached;
    - Scoring;
    - Storing maximum points.

      Points will be accrued as follows:
      - 1 row is 100 points;
      - 2 rows is 300 points;
      - 3 rows is 700 points;
      - 4 rows is 1500 points;
    - Level mechanics - each time a player gains 600 points, the level increases by 1.The maximum number of levels is 10.
  

- Added support for all the buttons provided on the physical console for control:
    - Start game (Enter),
    - Pause ('p' key),
    - End game (Escape),
    - Left arrow - movement of the tetramino to the left,
    - Right arrow - movement of the tetramino to the right,
    - Down arrow - tetramino falls,
    - Rotate (using 'Up' key).

