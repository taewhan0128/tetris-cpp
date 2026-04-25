## Tetris (C++)
A simple implementation of the classic Tetris built in C++ using a modular object-oriented design.

This project implements the core mechanics of Tetris including piece spawning, rotation, collision detection, board management, and rendering.

## Features
- 7 classic Tetris block types
- Block rotation system
- Collision detection
- Clear line when filled
- Board grid management
- Next piece preview
- Random piece generation
- Colored block rendering
- Object-oriented architecture

## How it works
- Board

The board is represented as a 2D grid:

BOARD_WIDTH × BOARD_HEIGHT

Each cell stores:

POS_FREE   -> empty cell
POS_FILLED -> occupied cell

- Pieces

Each Tetris piece is stored as a 4×4 matrix.

Example:

0 1 0 0
1 2 1 0
0 0 0 0
0 0 0 0

Where:

0 = empty
1 = block
2 = rotate centered block

- Game Loop

The main loop performs:

1. Process input
2. Update piece position
3. Check collisions
4. Lock piece if necessary
5. Draw board and pieces

## Controls
Controls
Key	Action
←	Move piece left
→	Move piece right
↓	Move piece down
↑	Rotate piece
ESC	Exit game

## Building the Project
Requirements:

- C++ compiler (g++, clang++, etc.)
- SDL or graphics framework used in IO implementation

Compile Example:

`g++ *.cpp -o tetris -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_gfx`

Run:

`./tetris`

## Learning Goals

This project was built to practice:

- Object-oriented C++
- Game loop architecture
- Collision detection
- 2D grid systems
- Basic graphics rendering

## Future Improvements
- Score system
- Hold piece mechanic
- Smooth animations
- Sound effects
- Better rendering