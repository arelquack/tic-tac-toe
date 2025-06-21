#ifndef PLAYER_H
#define PLAYER_H

#include "tictactoe.h"

/**
 * Handles user input for placing a symbol (X or O) on the board.
 * Validates that the position is within bounds and not already filled.
 *
 * @param state  Pointer to the current game state.
 * @param symbol Character symbol for the current player (PLAYER_X or AI).
 */
void player_move(GameState *state, char symbol);

#endif