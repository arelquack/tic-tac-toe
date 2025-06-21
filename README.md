# Tic Tac Toe with Unbeatable AI

A modular, console-based Tic Tac Toe game implemented in C, featuring an **unbeatable AI** powered by the **Minimax algorithm with alpha-beta pruning**. Designed with **high modularity, high cohesion, and low coupling**, this project demonstrates strong software engineering principles suitable for a portfolio or academic showcase.

---

## 📌 Project Overview

This Tic Tac Toe game supports two modes: **Player vs. Player (PvP)** and **Player vs. AI (PvAI)**. The AI leverages the **Minimax algorithm with alpha-beta pruning** for optimal moves, enhanced with **position-based heuristics** to prioritize strategic positions (center and corners). The game features a **colorful terminal-based UI** with ASCII art, making it both functional and visually appealing.

---

## ✨ Key Features

- 🎮 **Game Modes**: Player vs Player (PvP) or challenge an Unbeatable AI (PvAI)
- 🤖 **Unbeatable AI**: Minimax with alpha-beta pruning and position-based move priority
- 📦 **Modular Design**: Organized into separate modules (board, player, ai, game) for maintainability
- 🎨 **User-Friendly UI**: Colored symbols (blue for `X`, red for `O`) with ASCII art
- 🛡️ **Robust Error Handling**: Validates player inputs and prevents invalid moves
- ⚡ **Optimized Performance**: Minimized unnecessary evaluations via pruning and heuristics

---

## ⚙️ Installation

### Prerequisites

- **C Compiler**: GCC (MinGW for Windows or native GCC for Linux/macOS)
- **Operating System**: Windows, Linux, or macOS  
- Optional: `make` (for automated builds)

---

## 📁 Project Structure

```

tic-tac-toe/
├── include/
│   ├── tictactoe.h   # Core definitions (GameState, constants)
│   ├── board.h       # Board-related function declarations
│   ├── player.h      # Player input handling
│   ├── ai.h          # AI logic (Minimax, alpha-beta pruning)
│   └── game.h        # Game loop and initialization
├── src/
│   ├── main.c        # Main entry point
│   ├── board.c       # Board rendering, checking, and reset
│   ├── player.c      # Player move input
│   ├── ai.c          # AI move logic with Minimax
│   └── game.c        # Game control flow
├── Makefile          # Optional build script
└── README.md         # Project documentation

````

---

## 🛠️ Build Instructions

```bash
# Clone the repository
git clone <repository-url>
cd tic-tac-toe

# Compile using GCC
gcc -I include src/main.c src/board.c src/player.c src/ai.c src/game.c -o tictactoe

# Or, if you have make:
make

# Run the game
./tictactoe        # Linux / macOS
tictactoe.exe      # Windows (cmd or terminal that supports ANSI colors)
````

---

## 🧹 Cleaning Build Artifacts

```bash
make clean
```

---

## 🎮 How to Play

1. Run the game and select a mode:

   ```
   1. Player vs Player
   2. Player vs AI
   ```

2. Input your move by entering row and column numbers (1-3).

3. For PvAI:

   * You are `X`, and the AI is `O`
   * AI responds immediately after your move

4. The game ends when:

   * A player wins
   * The board is full (draw)
   * You choose not to play again (`y/n` prompt)

---

## 💡 Technical Highlights

### ✅ Software Engineering Principles

* **High Modularity**: Split into 4 cohesive modules (`board`, `ai`, `player`, `game`)
* **High Cohesion**: Each file is responsible for a single concern
* **Low Coupling**: Minimal dependency between components, communication via `GameState` struct

### 🧠 AI Optimization

* **Minimax Algorithm**: Recursively evaluates all possible moves
* **Alpha-Beta Pruning**: Skips unnecessary branches to speed up decision-making
* **Heuristic Prioritization**:

  * Center: `4`
  * Corners: `3`
  * Edges: `2`
* **Scoring System**:

  * +10 for AI win
  * -10 for player win
  * 0 for draw

### 🐞 Bug Fixes & Enhancements

* Fixed invalid loop indexing in `ai.c`
* Corrected constant usage (`PLAYER_X` vs `PLAYER`)
* Resolved header inclusion issues to prevent linker errors
* Improved input validation for robustness

### 🎨 UI Design

* ASCII board with:

  * Blue `X` (`\033[1;34m`)
  * Red `O` (`\033[1;31m`)
* Works well in ANSI-supported terminals

---

## 🔮 Future Improvements

* ✅ Score tracking system
* 💾 Save/load game state
* 🧠 Difficulty levels for AI (easy, medium, hard)
* 🧱 Support for larger board sizes (e.g., 4x4, 5x5)

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Commit your changes: `git commit -m "Add feature"`
4. Push to your branch: `git push origin feature-name`
5. Open a Pull Request with a clear description

> Please follow the existing modular structure and add test coverage where applicable.

---

## 🙏 Acknowledgments

* Built as a portfolio project to demonstrate **C programming** and **AI logic**
* Inspired by classic implementations of Tic Tac Toe
* Special thanks to feedback from AI assistants and peers for optimization tips

---

**Developed by Arel Zandra** – as a showcase of clean code, algorithmic thinking, and software engineering best practices in C.
