#include <stdio.h>

void TakeInputs(int values[], int count);
void HHfunction(int values[], int count); // Make histogram horizontally
void VHfunction(int values[], int count); // Make histogram vertically
int max(int a, int b); // Function prototype for max

int main() {
    int count;

    printf("Enter the number of values you want to display: ");
    scanf("%d", &count);

    int values[count]; 

    TakeInputs(values, count);

    printf("\nHorizontal Histogram:\n");
    HHfunction(values, count);

    printf("\nVertical Histogram:\n");
    VHfunction(values, count);

    return 0;
}

void TakeInputs(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter integer value %d: ", i + 1);
        scanf("%d", &values[i]);
    }
}

void HHfunction(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", values[i]);
        for (int j = 0; j < values[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void VHfunction(int values[], int count) {
    
    int maxval = 0;
    for (int i = 0; i < count; i++) {
        maxval = max(values[i], maxval);
    }
    
    // Print the vertical histogram
    for (int i = maxval; i > 0; i--) { // Start from maxval down to 1
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* "); 
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}