#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int arr1[3][3] = {0};
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr1[i][j] = (rand() % 10) + 3;
        }
    }

    int arr2[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = (rand() % 10);
        }
    }

    printf("Here is ARRAY 01:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf("Here is ARRAY 02:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    int result[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                r
