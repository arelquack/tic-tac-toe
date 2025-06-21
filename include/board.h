#ifndef BOARD_H
#define BOARD_H

#include "tictactoe.h"

void initialize_board(GameState *state);
void print_board(const GameState *state);
bool is_board_full(const GameState *state);
int check_winner(const GameState *state);

#endif