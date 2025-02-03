#include <stdio.h>

int main() {
    int matchsticks = 21;
    int player_pick, computer_pick;

    printf("Welcome to the Matchstick Game!\n");
    printf("There are 21 matchsticks. You can pick 1, 2, 3, or 4 matchsticks on each turn.\n");
    printf("The player forced to pick the last matchstick loses the game.\n");

    while (matchsticks > 1) {
        // Player's turn
        printf("\nMatchsticks remaining: %d\n", matchsticks);
        printf("Pick 1, 2, 3, or 4 matchsticks: ");
        scanf("%d", &player_pick);

        // Validate player input
        if (player_pick < 1 || player_pick > 4) {
            printf("Invalid choice. Please pick between 1 and 4 matchsticks.\n");
            continue;
        }

        // Reduce the number of matchsticks based on player's choice
        matchsticks -= player_pick;

        // Check if the player lost
        if (matchsticks == 1) {
            printf("Matchsticks remaining: %d\n", matchsticks);
            printf("You are forced to pick the last matchstick. You lose!\n");
            break;
        }

        // Computer's turn - always picks to leave a multiple of 5
        computer_pick = (matchsticks - 1) % 5;
        if (computer_pick == 0) {
            computer_pick = 1; // If multiple of 5 is already present, pick 1 to force the player
        }
        
        printf("Computer picks %d matchstick(s).\n", computer_pick);
        matchsticks -= computer_pick;

        // Check if the computer lost (it shouldn't if played correctly)
        if (matchsticks == 1) {
            printf("Matchsticks remaining: %d\n", matchsticks);
            printf("Computer is forced to pick the last matchstick. You win!\n");
            break;
        }
    }

    return 0;
}
