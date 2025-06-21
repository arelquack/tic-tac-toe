#include <stdio.h>
#include <unistd.h>
#include "../include/game.h"
#include "../include/board.h"
#include "../include/player.h" 
#include "../include/ai.h"

// Inisialisasi permainan
void initialize_game(GameState *state, int mode) {
    state->mode = mode;
    state->is_player_turn = true;
    initialize_board(state);
}

// Main game loop
void play_game(GameState *state) {
    while (true) {
        print_board(state);

        // === Player vs Player Mode ===
        if (state->mode == 1) {
            if (state->is_player_turn) {
                printf("Giliran Pemain 1 (X): \n");
                player_move(state, PLAYER_X);
            } else {
                printf("Giliran Pemain 2 (O): \n");
                player_move(state, AI);
            }
        }

        // === Player vs AI Mode ===
        else {
            if (state->is_player_turn) {
                printf("Kamu (X): \n");
                player_move(state, PLAYER_X);
            } else {
                printf("AI (O): \n");
                ai_move(state);
                sleep(1); // Add delay for realism
            }
        }

        // ==== Check for winner or draw ===
        int winner = check_winner(state);
        if (winner) {
            print_board(state);
            if (winner == 1) {
                printf("Pemain %s menang!\n", (state->mode == 1) ? "1 (X)" : "(X)");
            } else {
                printf("Pemain %s menang!\n", (state->mode == 1) ? "2 (O)" : "AI (O)");
            }
            return;
        }

        // === Check for draw ===
        if (is_board_full(state)) {
            print_board(state);
            printf("SERI!\n");
            return;
        }

        // === Switch turn ===
        state->is_player_turn = !state->is_player_turn;
    }
}