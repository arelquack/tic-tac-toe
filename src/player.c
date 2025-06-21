#include <stdio.h>
#include "../include/player.h"

// Input Pemain
void player_move(GameState *state, char symbol) {
    int row, col;

    while (true) {
        printf("Masukkan baris (1-3) dan kolom: ");
        scanf("%d %d", &row, &col);

        // Turn the input into zero-based index
        row--; 
        col--;
        
        // Input validation: position must be within bounds and cell must be empty
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && state->board[row][col] == EMPTY) {
            state->board[row][col] = symbol;
            return;
        }
        
        printf("Posisi salah atau sudah terisi. Coba lagi!\n");
    }
}