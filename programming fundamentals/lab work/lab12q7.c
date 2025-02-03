#include <stdio.h>
#include <stdlib.h>

int main() {
	int numPoints;
	float totalProfit = 0.0;

	printf("Enter the total number of points: ");
	scanf("%d", &numPoints);

	if (numPoints <= 0) {
		printf("Error: The number of points must be greater than zero.\n");
		return 1;
	}

	float *fees = (float *)malloc(numPoints * sizeof(float));
	if (fees == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	for (int i = 0; i < numPoints; i++) {
		printf("Enter the fee for point %d: ", i + 1);
		scanf("%f", &fees[i]);

		while (fees[i] < 0) {
			printf("Error: Fee cannot be negative. Please enter a valid fee for point %d: ", i + 1);
			scanf("%f", &fees[i]);
		}

		totalProfit += fees[i];
	}

	printf("Total profit generated: %.2f", totalProfit);
	free(fees);

	return 0;
}
