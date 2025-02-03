#include <stdio.h>

int findUniqueElements(int array[], int n) {
    int frequency[10] = {0};  

    // Count frequency of each element in the array
    for (int i = 0; i < n; i++) {
        frequency[array[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (frequency[array[i]] > 0) {
            printf("%d ", array[i]);
            frequency[array[i]] = 0;  // Set frequency to 0 to avoid printing again
        }
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Without Duplicates: ");
    findUniqueElements(array, n);
    printf("\n");
    
    return 0;
}
