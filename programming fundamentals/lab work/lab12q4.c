#include <stdio.h>
#include <stdlib.h>

int main() {
    int testcases;

    printf("Enter number of test cases: ");
    scanf("%d", &testcases);

    while (testcases--) {
        int n;

        printf("Enter number of elements in the array: ");
        scanf("%d", &n);

        int *response = (int *)malloc(n * sizeof(int));
        if (response == NULL) {
            printf("Memory allocation failed for sequence array.\n");
            return 1;
        }

        int *frequency = (int *)calloc(10001, sizeof(int));
        if (frequency == NULL) {
            printf("Memory allocation failed for frequency array.\n");
            free(response);
            return 1;
        }

        printf("Enter elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &response[i]);
            frequency[response[i]]++;  
        }

        
        int maxFreq = 0;
        int result = 10001;  

        for (int i = 1; i <= 10000; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                result = i;  
            } else if (frequency[i] == maxFreq && i < result) {
                result = i;  
            }
        }

        printf("Number with highest frequency: %d\n", result);

        free(response);
        free(frequency);
    }

    return 0;
}
