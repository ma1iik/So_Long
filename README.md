
# so_long

## Description

**so_long** is a small 2D game project developed in C as part of the École 42 curriculum. The game objective is simple: the player navigates a map, collects items, and escapes through the exit. This project is intended to enhance skills in handling textures, sprites, and basic game mechanics using the MiniLibX graphics library.

## Features

- Implements a basic 2D game using MiniLibX, allowing a top-down or profile view.
- Character movement is controlled with **W, A, S, D** keys (or optionally **ZQSD** or arrow keys).
- Tracks and displays the number of moves in the terminal after each action.
- Enforces map boundaries to prevent the player from moving through walls.
- Supports collectibles and an exit point.

## Compilation and Usage

To compile the project, use the provided Makefile by running:

```bash
make
```

## Project Structure

- **so_long.c**: Main program that initializes the game, manages input, and starts the game loop.
- **map.c**: Manages map parsing, checks map validity, and ensures it follows the expected layout rules.
- **graphics.c**: Handles sprite rendering, textures, and updates using MiniLibX.
- **libft/**: Custom utility library with helper functions.
- **Makefile**: Manages the compilation of the project and provides targets for building and cleaning.

## Map Requirements

The game uses maps formatted as `.ber` files, which must adhere to the following rules:

- `1` for walls, `0` for free space, `C` for collectibles, `E` for the exit, and `P` for the player starting position.
- Maps must contain at least one collectible, one exit, and one starting position.
- The map should be rectangular and closed by walls.

### Example Map

Here is an example of a minimal map in `.ber` format:

```
1111111
1P0C0E1
1111111
```

## How to Run

After compiling, you can run the game with the following command:

```bash
./so_long path/to/map.ber
```

## Author

Project developed by [Malik](https://github.com/ma1iik) as part of the École 42 curriculum.
