#include <stdio.h>

// Recursive function to print the array
void printArray(int arr[], int arrSize, int currentIndex) {
    if (currentIndex < arrSize) {
        printf("%d ", arr[currentIndex]);
        printArray(arr, arrSize, currentIndex + 1);
    }
}

int main() {    
    int currentIndex = 0;
    int arrSize = 5;
    int arr[] = {0, 1, 2, 3, 4};

    // Call the recursive function to print the array
    printArray(arr, arrSize, currentIndex);

    return 0;
}
