#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/ai.h"
#include "../include/board.h"

/*
    Heuristic priority matrix for positional evaluation.
    Center (1,1) has the highest strategic value (4), followed by corners (3), and edges (2).
*/
static const int priority[SIZE][SIZE] = {
    {3, 2, 3},
    {2, 4, 2},
    {3, 2, 3}
};

int minimax (char temp_board[SIZE][SIZE], int depth, bool is_maximizing, char ai_symbol, char player_symbol, int alpha, int beta) {
    // Copy board into temporary GameState for winner evaluation
    GameState temp_state = {{0}};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp_state.board[i][j] = temp_board[i][j];
        }
    }

    // Terminal condition checks
    int score = check_winner(&temp_state);
    if (score == 1) return -10 + depth; // Player wins
    if (score == -1) return 10 - depth; // AI wins
    if (is_board_full(&temp_state)) return 0; // Draw

    // Recursive Minimax with pruning
    if (is_maximizing) {
        int best = -1000;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (temp_board[i][j] == EMPTY) {
                    temp_board[i][j] = ai_symbol;
                    int val = minimax(temp_board, depth + 1, false, ai_symbol, player_symbol, alpha, beta);
                    temp_board[i][j] = EMPTY;

                    best = max(best, val);
                    alpha = max(alpha, best);
                    
                    // Alpha-Beta Pruning
                    if (beta <= alpha) return best; // Ini alpha-beta pruning
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
                    int val = minimax(temp_board, depth + 1, true, ai_symbol, player_symbol, alpha, beta);
                    temp_board[i][j] = EMPTY;

                    best = min(best, val);
                    beta = min(beta, best);
                    
                    if (beta <= alpha) return best;
                }
            }
        }
        return best;
    }
}

void ai_move(GameState *state) {
    // If it's the first move and center is available, take it!
    int move_count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (state->board[i][j] != EMPTY) 
                move_count++;
                
    if (move_count == 0 && state->board[1][1] == EMPTY) {
        state->board[1][1] = AI;
        printf("AI memilih baris 2, kolom 2\n");
        return;
    }

    // Evaluate all possible moves using Minimax and prioritize optimal ones
    int best_val = -1000;
    int move_row = -1, move_col = -1;
    int best_priority = -1;
    char temp_board[SIZE][SIZE];

    // Copy current board state to a temporary board for evaluation
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp_board[i][j] = state->board[i][j];
    
    // Try all possible moves
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (temp_board[i][j] == EMPTY) {
                temp_board[i][j] = AI;

                int move_val = minimax(temp_board, 0, false, AI, PLAYER_X, -1000, 1000);
                temp_board[i][j] = EMPTY;

                // Choose best score or highest priority if scores are equal
                if (move_val > best_val) {
                    move_row = i;
                    move_col = j;
                    best_val = move_val;
                    best_priority = priority[i][j];
                }
            }
        }
    }

    // Apply the chosen move
    if (move_row != -1 && move_col != -1) {
        state->board[move_row][move_col] = AI;
        printf("AI memilih baris %d, kolom %d\n", move_row + 1, move_col + 1);
    }
}