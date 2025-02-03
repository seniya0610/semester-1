#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grid[4];
    
    for (int i = 0; i < 5; i++){
        printf("enter value %d\n", i+1);
        scanf(" %d", &grid[i]);
    }
    
    for (int i = 0; i < 5; i++){
        printf("element - %d : %d\n", i+1, grid[i]);
    }
    
    int min = grid[0];
    int ss = -1; //second smallest value
    
    for (int i = 0; i < 4; i++){
        if (grid[i+1] < min){
        ss = min;
        min = grid[i+1];
        }
        else if (grid[i+1] > min){
            if (ss == -1 || grid[i+1] < ss)
            ss = grid[i+1];
        }
    }
    printf ("second smallest value = %d", ss);
}
