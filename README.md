# so_long

**so_long** is a project developed as part of the 42 School curriculum. It is a small graphical game written in C using the MiniLibX library for rendering 2D graphics. The main objective is to collect all the collectibles and reach the exit, avoiding obstacles and following the map rules.

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Project Structure](#project-structure)
- [Game Rules](#game-rules)
- [Credits](#credits)

## Description

The game loads a map from a `.ber` file, where the player can move in four directions. The goal is to collect all the collectibles (`C`) and reach the exit (`E`). Walls (`1`) block movement, and the player (`P`) can only move onto empty spaces (`0`) or collectibles.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/PabloFC/so_long.git
   cd so_long
   ```

2. **Compile the project (requires `make` and MiniLibX):**
   ```bash
   make
   ```
   > Make sure you have the MiniLibX library installed. On Linux-based systems, check the `Makefile` and requirements for dependency installation.

## Usage

Run the game with the following command, providing a valid map:

```bash
./so_long maps/map1.ber
```

## Controls

- **W / ↑** : Move up
- **A / ←** : Move left
- **S / ↓** : Move down
- **D / →** : Move right
- **ESC** : Exit the game

## Project Structure

```
so_long/
├── includes/          # Header files (.h)
├── src/               # Main source code (.c)
├── maps/              # Example maps in .ber format
├── Makefile
└── README.md
```

## Game Rules

- The map must be rectangular and surrounded by walls.
- There must be at least one exit (`E`), one player (`P`), and one collectible (`C`).
- The player can only win after collecting all collectibles and reaching the exit.
- It is recommended to validate maps before playing.

## Credits

Project developed by [PabloFC](https://github.com/PabloFC) as part of the 42 School program.

---

> “This project was made for educational purposes as part of the 42 School curriculum.”
