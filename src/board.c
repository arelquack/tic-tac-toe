#include <stdio.h>
#include "../include/board.h"

/*
    Warna untuk User Interface
    - Warna Biru: \033[0;34m
    - Warna Merah: \033[0;31m
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
                printf("\033[1;34m %c \033[0m|", state->board[i][j]);
            } else if (state->board[i][j] == AI) {
                printf("\033[1;31m %c \033[0m|", state->board[i][j]);
            } else {
                printf(" %c |", state->board[i][j]);
            }
        }
        printf("\n  +---+---+---+\n");
    }
}

// Cek apakah papan sudah penuh
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

// Cek pemenang (1: Player X, -1: Player O/AI, 0: belum ada)
int check_winner(const GameState *state) {
    // Cek baris
    for (int i = 0; i < SIZE; i++) {
        if (state->board[i][0] == state->board[i][1] && state->board[i][1] == state->board[i][2] && state->board [i][0] != EMPTY) {
            return (state->board[i][0] == PLAYER_X) ? 1 : -1;
        }
    }

    // Cek kolom
    for (int j = 0; j < SIZE; j++) {
        if (state->board[0][j] == state->board[1][j] && state->board[1][j] == state->board[2][j] && state->board[0][j] != EMPTY) {
            return (state->board[0][j] == PLAYER_X) ? 1 : -1;
        }
    }

    // Cek diagonal
    if (state->board[0][0] == state->board[1][1] && state->board[1][1] == state->board[2][2] && state->board[0][0] != EMPTY) {
        return (state->board[0][0] == PLAYER_X) ? 1 : -1;
    }
    if (state->board[0][2] == state->board[1][1] && state->board[1][1] == state->board[2][0] && state->board[0][2] != EMPTY) {
        return (state->board[0][2] == PLAYER_X) ? 1 : -1;
    }
    return 0;
}