#ifndef GAME_H
#define GAME_H

#include "tictactoe.h"

/**
 * Initializes the game state, including the board and game mode.
 *
 * @param state Pointer to the GameState structure to be initialized.
 * @param mode  Game mode: 
 *              1 - Player vs Player
 *              2 - Player vs AI
 */
void initialize_game(GameState *state, int mode);

/**
 * Runs the main game loop for Tic Tac Toe.
 * Handles both Player vs Player and Player vs AI modes.
 *
 * @param state Pointer to the current game state.
 */
void play_game(GameState *state);

#endif