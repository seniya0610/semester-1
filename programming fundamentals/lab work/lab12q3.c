#include <stdio.h>
#include <stdlib.h>

void addNumber(float **array, int *size, int *capacity) {
    if (*size == *capacity) {
        *capacity *= 2;
        *array = realloc(*array, *capacity * sizeof(float));
        if (*array == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("Array capacity doubled to %d.\n", *capacity);
    }

    printf("Enter a number to add: ");
    scanf("%f", &(*array)[*size]);
    (*size)++;
}

void displayNumbers(float *array, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current numbers in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void removeLastNumber(float **array, int *size, int *capacity) {
    if (*size == 0) {
        printf("Array is already empty.\n");
        return;
    }

    (*size)--;

    // Reduce capacity if usage drops significantly
    if (*size <= *capacity / 4 && *capacity > 4) {
        *capacity /= 2;
        *array = realloc(*array, *capacity * sizeof(float));
        if (*array == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        printf("Array capacity reduced to %d.\n", *capacity);
    }

    printf("Last number removed. Current size: %d\n", *size);
}

int main() {
    int capacity = 4;
    int size = 0;
    float *array = malloc(capacity * sizeof(float));
    if (array == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    int choice;
    do {
        printf("\nDynamic Array Management\n");
        printf("1. Add a number\n");
        printf("2. Display numbers\n");
        printf("3. Remove last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addNumber(&array, &size, &capacity);
            break;
        case 2:
            displayNumbers(array, size);
            break;
        case 3:
            removeLastNumber(array, &size, &capacity);
            break;
        case 4:
            free(array);
            printf("Memory freed. Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
