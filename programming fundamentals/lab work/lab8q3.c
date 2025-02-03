#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void findSaddlePoints(int grid[3][3]);

int main() {
    int grid[3][3];
    
    srand(time(NULL));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = (rand() % 10) + 1;
        }
    }
    
    printf("Grid:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    findSaddlePoints(grid);
    
    return 0;
}

void findSaddlePoints(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        int rM = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < 3; j++) {
            if (grid[i][j] < rM) {
                rM = grid[i][j];
                minIndex = j;
            }
        }

        int colMax = INT_MIN;
        for (int k = 0; k < 3; k++) {
            if (grid[k][minIndex] > colMax) {
                colMax = grid[k][minIndex];
            }
        }

        if (rM == colMax) {
            printf("Saddle point found at (%d, %d): %d\n", i, minIndex, rM);
        }
    }
}
