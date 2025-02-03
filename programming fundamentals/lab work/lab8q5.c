#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of rows for the top half of the diamond: ");
    scanf("%d", &n);

    // Top half of the diamond
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Bottom half of the diamond
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
