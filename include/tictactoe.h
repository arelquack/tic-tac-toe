#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdbool.h>

// Board size (3x3)
#define SIZE 3

// Symbols representation on the board
#define EMPTY ' ' // Empty cell
#define PLAYER_X 'X' // Player X's symbol
#define AI 'O' // Player 2 / AI symbol


/**
 * Main structure representing the game state.
 */
typedef struct {
    char board[SIZE][SIZE]; // 3x3 game board
    bool is_player_turn; // true if it's Player X's turn, false for Player O (AI)
    int mode; // 1 for PvP, 2 for PvAI
} GameState;

#endif