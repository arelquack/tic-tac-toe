#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "../include/game.h"

/**
 * Entry point of the Tic Tac Toe game.
 * Handles game mode selection and replay loop.
 */
int main() {
    // Seed the random number generator (optional if needed later)
    srand(time(NULL));

    GameState state;
    int mode;
    char play_again;

    do {
        printf("\n=== TIC TAC TOE ===\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs AI\n");
        printf("Pilih mode permainan (1/2): ");
        scanf("%d", &mode);

        // Validate input
        if (mode != 1 && mode != 2) {
            printf("Mode invalid. Pilih 1 atau 2.\n");
            continue;
        }

        // Initialize and play game
        initialize_game(&state, mode);
        play_game(&state);

        // Ask user to play again
        printf("\nMain lagi? (y/n): ");
        scanf(" %c", &play_again); // Note: space before %c to consume newline
    } while (play_again == 'y' || play_again == 'Y');
    
    printf("Terima kasih telah bermain!\n");
    
    return 0;
}