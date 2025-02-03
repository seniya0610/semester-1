#include <stdio.h>

// Recursive function to find the target in the array
int searchArray(int array[], int arraySize, int targetValue) {
    if (arraySize < 0) {
        return 0;
    } else {
        if (array[arraySize] == targetValue) {
            return 1;
        } else {
            return searchArray(array, arraySize - 1, targetValue);
        }
    }
}

int main() {
    int targetValue, arraySize;

    // Input: Array size
    printf("Enter array size: ");
    scanf("%d", &arraySize);

    int array[arraySize];

    // Input: Array elements
    for (int i = 0; i < arraySize; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Input: Target value to search for
    printf("Enter the target value: ");
    scanf("%d", &targetValue);

    // Call recursive function and check if target is found
    int isFound = searchArray(array, arraySize - 1, targetValue);
    if (isFound) {
        printf("Target found.\n");
    } else {
        printf("Target not found.\n");
    }

    return 0;
}
