#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdbool.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define AI 'O'

typedef struct {
    char board[SIZE][SIZE];
    bool is_player_turn;
    int mode; // 1 for PvP, 2 for PvAI
} GameState;

#endif