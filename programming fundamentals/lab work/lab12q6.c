#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;

	printf("Enter the number of elements (1 to 100): ");
	scanf("%d", &n);

	if (n < 1 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	int *array = (int *)malloc(n * sizeof(int));
	if (array == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter the elements:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	int largest = array[0];

	for (int i = 1; i < n; i++) {
		if (array[i] > largest) {
			largest = array[i];
		}
	}

	printf("The largest element is: %d\n", largest);

	free(array);

	return 0;
}
