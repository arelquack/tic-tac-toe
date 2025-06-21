#include <stdio.h>
#include <stdlib.h>
#include "../include/ai.h"
#include "../include/board.h"

// Algoritma Minimax
int minimax (char temp_board[SIZE][SIZE], int depth, bool is_maximizing, char ai_symbol, char player_symbol) {
    GameState temp_state = {{0}};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_state.board[i][j] = temp_board[i][j];
        }
    }
    int score = check_winner(&temp_state);
    if (score == 1) return -1 + depth; // Player X menang
    if (score == -1) return 1 - depth; // AI/O menang
    if (is_board_full(&temp_state)) return 0;

    if (is_maximizing) {
        int best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (temp_board[i][j] == EMPTY) {
                    temp_board[i][j] = ai_symbol;
                    best = max(best, minimax(temp_board, depth + 1, false, ai_symbol, player_symbol));
                    temp_board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (temp_board[i][j] == EMPTY) {
                    temp_board[i][j] = player_symbol;
                    best = min(best, minimax(temp_board, depth + 1, true, ai_symbol, player_symbol));
                    temp_board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

// Gerakan AI
void ai_move(GameState *state) {
    int best_val = -1000;
    int move_row = -1, move_col = -1;
    char temp_board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_board[i][j] = state->board[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (temp_board[i][j] == EMPTY) {
                temp_board[i][j] = AI;
                int move_val = minimax(temp_board, 0, false, AI, PLAYER_X);
                temp_board[i][j] = EMPTY;
                if (move_val > best_val) {
                    move_row = i;
                    move_col = j;
                    best_val = move_val;
                }
            }
        }
    }
    if (move_row != -1 && move_col != -1) {
        state->board[move_row][move_col] = AI;
        printf("AI memilih baris %d, kolom %d\n", move_row + 1, move_col + 1);
    }
}