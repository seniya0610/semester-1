#include <stdio.h>
#include <stdlib.h>

void insertElement(int **arr, int *size, int *capacity, int position, int value) {
    if (*size == *capacity) {
        
        *capacity *= 2;
        *arr = (int *)realloc(*arr, *capacity * sizeof(int));
        if (*arr == NULL) {
            printf("Memory allocation failed for insertion.\n");
            exit(1);
        }
    }

    // Shift elements to the right to create space for the new element
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert the new element at the specified position
    (*arr)[position] = value;
    (*size)++;
}

void deleteElement(int **arr, int *size, int position) {
    // Shift elements to the left to remove the element at the specified position
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Decrease the size of the array
    (*size)--;
}

int main() {
    int testcases;
    printf("Enter number of test cases: ");
    scanf("%d", &testcases);

    while (testcases--) {
        int N;
        printf("Enter number of elements in the array: ");
        scanf("%d", &N);

      
        int *arr = (int *)malloc(N * sizeof(int));
        int capacity = N;
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the elements:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int choice;
        printf("Enter your choice:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int position, value;
            printf("Enter the position to insert (0 to %d): ", N);
            scanf("%d", &position);
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertElement(&arr, &N, &capacity, position, value);

            printf("Array after insertion:\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

        } else if (choice == 2) {
            int position;
            printf("Enter the position to delete (0 to %d): ", N - 1);
            scanf("%d", &position);
            deleteElement(&arr, &N, position);

            printf("Array after deletion:\n");
            for (int i = 0; i < N; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } else {
            printf("Invalid choice.\n");
        }

        free(arr);
    }

    return 0;
}
