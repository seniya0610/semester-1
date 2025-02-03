#include <stdio.h>

void findCommonElements(int array1[], int n1, int array2[], int n2) {
    int found;
    
    printf("Common elements: ");
    for (int i = 0; i < n1; i++) {
        found = 0;
        for (int j = 0; j < n2; j++) {
            if (array1[i] == array2[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("%d ", array1[i]);
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;
    
    printf("Enter the number of elements for the first array: ");
    scanf("%d", &n1);
    
    int array1[n1];
    
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("Enter the number of elements for the second array: ");
    scanf("%d", &n2);
    
    int array2[n2];
    
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    // Find and print common elements
    findCommonElements(array1, n1, array2, n2);
    
    return 0;
}
