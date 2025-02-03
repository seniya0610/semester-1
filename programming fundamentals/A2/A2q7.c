#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void initializeGrid(char grid[6][5]);
int SearchVertical(char grid[6][5], const char *target);
int SearchHorizontal(char grid[6][5], const char *target);

int main() {
    char grid[6][5];
    int score = 0;
    initializeGrid(grid);

    char target[7];

    printf("Welcome to the game! Press 'Q' to quit at any time.\n"); 
    while (1) {
        printf("Which string would you like to find? ");
        scanf("%6s", target);
        
        for (int i = 0; i < strlen(target); i++) {
            if (target[i] >= 'a' && target[i] <= 'z') {
                target[i] = target[i] - 32;// Convert uppercase to lowercase
            }
        }

        
        if (target[0] == 'Q' && target[1] == '\0') { 
            printf("Thank you for playing! Exiting the game.\n");
            break;
        }

        if (SearchVertical(grid, target)) {
            score += 1;
            printf("Found vertically\nScore: %d\n", score);
        } else {
            printf("Not found vertically\nScore: %d\n", score);
        }

        if (SearchHorizontal(grid, target)) {
            score += 1;
            printf("Found horizontally\nScore: %d\n", score);
        } else {
            printf("Not found horizontally\nScore: %d\n", score);
        }
    }

    return 0;
}

void initializeGrid(char grid[6][5]) {
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    srand(time(NULL));

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = letters[rand() % 26];
            printf("%c\t", grid[i][j]);
        }
        printf("\n");
    }
}

int SearchVertical(char grid[6][5], const char *target) {
    int len = strlen(target);
    
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i <= 6 - len; i++) {
            int found = 1;
            
            for (int k = 0; k < len; k++) {
                if (grid[i + k][j] != target[k]) {
                    found = 0;
                    break;
                }
            }

            if (found) {
                return 1;
            }
        }
    }
    return 0;
}

int SearchHorizontal(char grid[6][5], const char *target) {
    int len = strlen(target);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            int found = 1;
            
            for (int k = 0; k < len; k++) {
                if (grid[i][j + k] != target[k]) {
                    found = 0;
                    break;
                }
            }

            if (found) {
                return 1;
            }
        }
    }
    return 0;
}
