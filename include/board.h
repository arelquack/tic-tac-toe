#ifndef BOARD_H
#define BOARD_H

#include "tictactoe.h"

/**
 * Initializes the game board by setting all cells to EMPTY.
 *
 * @param state Pointer to the GameState structure.
 */
void initialize_board(GameState *state);

/**
 * Displays the current state of the game board with color formatting.
 * Player X will be displayed in blue, and AI (O) in red.
 *
 * @param state Pointer to the GameState structure.
 */
void print_board(const GameState *state);

/**
 * Checks whether the game board is full (i.e., no EMPTY cells).
 *
 * @param state Pointer to the GameState structure.
 * @return true if the board is full, false otherwise.
 */
bool is_board_full(const GameState *state);

/**
 * Determines if there is a winner in the current board state.
 *
 * @param state Pointer to the GameState structure.
 * @return  1 if Player X wins,
 *         -1 if Player O (AI) wins,
 *          0 if no winner yet.
 */
int check_winner(const GameState *state);

#endif