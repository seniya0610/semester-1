#include <stdio.h>

// Recursive function to perform Bubble Sort
void bubbleSort(int arr[], int arrSize) {
    if (arrSize <= 1) {
        return;
    }
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, arrSize - 1); // Recurse with reduced size
}

int main() {
    int arr[] = {2, 1, 0, 3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // Perform Bubble Sort
    bubbleSort(arr, arrSize);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
