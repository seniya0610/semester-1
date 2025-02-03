#include <stdio.h>

int main () {
    int columns, rows;

    // Get the number of columns and rows from the user
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int grid[rows][columns];
    int sum[columns];
    int max[columns];
    int min[columns];
    float average[columns];

    // Take input for the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }

    // Initialize sum, max, and min arrays
    for (int j = 0; j < columns; j++) {
        sum[j] = 0;
        max[j] = grid[0][j]; // Initialize max with the first element of each column
        min[j] = grid[0][j]; // Initialize min with the first element of each column
    }

    // Calculate sum, max, and min for each column
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            sum[j] += grid[i][j];
            
            if (grid[i][j] > max[j]) {
                max[j] = grid[i][j];
            }
            
            if (grid[i][j] < min[j]) {
                min[j] = grid[i][j];
            }
        }
        // Calculate the average for each column
        average[j] = (float)sum[j] / rows;
    }

    // Display results
    printf("\nResults:\n");
    for (int j = 0; j < columns; j++) {
        printf("Column %d: Max = %d, Min = %d, Average = %.2f\n", j, max[j], min[j], average[j]);
    }

    return 0;
}
