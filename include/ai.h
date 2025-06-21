#ifndef AI_H
#define AI_H

#include "tictactoe.h"

// Macro untuk max dan min
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int minimax(char temp_board[SIZE][SIZE], int depth, bool is_maximizing, char ai_symbol, char player_symbol);
void ai_move(GameState *state);

#endif