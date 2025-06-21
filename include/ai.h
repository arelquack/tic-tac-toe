#ifndef AI_H
#define AI_H

#include "tictactoe.h"

// Macro untuk max dan min
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * Minimax algorithm with Alpha-Beta Pruning to determine optimal move.
 *
 * @param temp_board     The current simulated game board.
 * @param depth          The current depth of the recursion tree.
 * @param is_maximizing  Flag indicating whether it's the AI's turn to maximize.
 * @param ai_symbol      The symbol used by the AI (e.g., 'O').
 * @param player_symbol  The symbol used by the player (e.g., 'X').
 * @param alpha          The best already explored option along the path to the root for the maximizer.
 * @param beta           The best already explored option along the path to the root for the minimizer.
 * @return               Evaluation score of the board.
 */
int minimax(char temp_board[SIZE][SIZE], int depth, bool is_maximizing, char ai_symbol, char player_symbol, int alpha, int beta);

/**
 * Determines the best move for the AI and updates the game state.
 *
 * @param state  Pointer to the current game state.
 */
void ai_move(GameState *state);

#endif