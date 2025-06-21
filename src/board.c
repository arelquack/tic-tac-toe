#include <stdio.h>
#include "../include/board.h"

/**
 * ANSI color codes for terminal UI.
 * - Blue (Player X): \033[1;34m
 * - Red  (AI / Player O): \033[1;31m
 */
#ifndef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

// Inisialisasi papan kosong
void initialize_board(GameState *state)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            state->board[i][j] = EMPTY;
        }
    }
}

// Cetak papan permainan
void print_board(const GameState *state)
{
    system(CLEAR_SCREEN);
    printf("\n=== TIC TAC TOE ===\n\n");
    printf("     1   2   3\n");
    printf("   +---+---+---+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (state->board[i][j] == PLAYER_X) {
                printf("\033[1;34m %c \033[0m|", state->board[i][j]); // Blue for Player X
            } else if (state->board[i][j] == AI) {
                printf("\033[1;31m %c \033[0m|", state->board[i][j]); // Red for AI
            } else {
                printf(" %c |", state->board[i][j]); // Empty cell
            }
        }
        printf("\n  +---+---+---+\n");
    }
}

bool is_board_full(const GameState *state) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (state->board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int check_winner(const GameState *state) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (state->board[i][0] == state->board[i][1] && state->board[i][1] == state->board[i][2] && state->board [i][0] != EMPTY) {
            return (state->board[i][0] == PLAYER_X) ? 1 : -1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (state->board[0][j] == state->board[1][j] && state->board[1][j] == state->board[2][j] && state->board[0][j] != EMPTY) {
            return (state->board[0][j] == PLAYER_X) ? 1 : -1;
        }
    }

    // Check diagonals
    if (state->board[0][0] == state->board[1][1] && state->board[1][1] == state->board[2][2] && state->board[0][0] != EMPTY) {
        return (state->board[0][0] == PLAYER_X) ? 1 : -1;
    }
    if (state->board[0][2] == state->board[1][1] && state->board[1][1] == state->board[2][0] && state->board[0][2] != EMPTY) {
        return (state->board[0][2] == PLAYER_X) ? 1 : -1;
    }

    // No winner yet
    return 0;
}