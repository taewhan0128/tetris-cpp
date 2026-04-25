# Tetris (C++)

A simple implementation of the classic **Tetris** built in C++ using a modular object-oriented design.

This project implements the core mechanics of Tetris including piece spawning, rotation, collision detection, board management, and rendering.

---

## Features

- 7 classic Tetris block types
- Block rotation system
- Collision detection
- Line clearing when a row is filled
- Board grid management
- Next piece preview
- Random piece generation
- Colored block rendering
- Object-oriented architecture

---

## How It Works

### Board

The board is represented as a 2D grid:

```
BOARD_WIDTH × BOARD_HEIGHT
```

Each cell stores one of the following values:

```
POS_FREE   -> empty cell
POS_FILLED -> occupied cell
```

---

### Pieces

Each Tetris piece is stored as a **4×4 matrix**.

Example:

```
0 1 0 0
1 2 1 0
0 0 0 0
0 0 0 0
```

Where:

```
0 = empty
1 = block
2 = rotation center
```

---

### Game Loop

The main loop performs the following steps:

```
1. Process player input
2. Update piece position
3. Check for collisions
4. Lock piece if necessary
5. Render the board and pieces
```

---

## Controls

| Key | Action |
|----|------|
| ← | Move piece left |
| → | Move piece right |
| ↓ | Move piece down |
| ↑ | Rotate piece |
| ESC | Exit game |

---

## Building the Project

### Requirements

- C++ compiler (`g++`, `clang++`, etc.)
- SDL or another graphics framework used in the `IO` implementation

### Compile

```
g++ *.cpp -o tetris -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_gfx
```

### Run

```
./tetris
```

---

## Learning Goals

This project was created to practice:

- Object-oriented programming in C++
- Game loop architecture
- Collision detection
- 2D grid systems
- Basic graphics rendering

---

## Future Improvements

- Score system
- Hold piece mechanic
- Smooth animations
- Sound effects
- Improved rendering