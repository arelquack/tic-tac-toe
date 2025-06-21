#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "../include/game.h"

int main() {
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
        if (mode != 1 && mode != 2) {
            printf("Mode invalid. Pilih 1 atau 2.\n");
            continue;
        }
        initialize_game(&state, mode);
        play_game(&state);
        printf("\nMain lagi? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');
    printf("Terima kasih telah bermain!\n");
    return 0;
}