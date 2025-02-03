#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	printf("enter number of elements in the array: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("enter numbers: ");
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			arr[i]++; //if odd make it even
		}
	}
	//print array
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

	return 0;
}