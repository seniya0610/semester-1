#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
   //initialization of random array
    const char arr1[] = { 'i', 'x', ' ', ' ' };
    int rows = 5;
    int cols = 5;
    char grid[rows][cols];
    
    // initialization of player
    int playerX = 0;
    int playerY = 0;
    char player = 'P';
    grid[playerX][playerY] = player;

    srand(time(NULL));

    // intilization of array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            
            int randomIndex = rand() % 4;
            grid[i][j] = arr1[randomIndex];
        }
    }

    int counter = 0;  // Score counter

    char move;
    while (1) {
        // Print the 2D array
        printf("2D Array (Grid):\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
        printf("Score: %d\n", counter);
    // Ask player for move
        printf("\nMove (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);
    // set the current index of player to null
        grid[playerX][playerY] = ' ';
        
    // set the new poistion according to positions
        int newX = playerX;
        int newY = playerY;

        if ((move == 'w' || move == 'W') && playerX > 0) {
            newX--;
        } else if ((move == 's' || move == 'S') && playerX < rows - 1) {
            newX++;
        } else if ((move == 'a' || move == 'A') && playerY > 0) {
            newY--;
        } else if ((move == 'd' || move == 'D') && playerY < cols - 1) {
            newY++;
        } else if (move == 'q' || move == 'Q') {
            printf("Exiting the game.\n");
            break;
        } else {
            printf("Invalid move or out of bounds! Try again.\n");
            continue;
        }

    // check obsticle
        if (grid[newX][newY] == 'x') {
            printf("Cannot move because of obstacle!\n");
        } else {

            playerX = newX;
            playerY = newY;

    // check item and update score
            if (grid[playerX][playerY] == 'i') {
                counter++;
                printf("You picked up an item! Score: %d\n", counter);
            }

            grid[playerX][playerY] = player;
        }
    }

    return 0;
}
