#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* ratings;
	int totalScore;
} Employee;

void inputEmployees(Employee **employees, int numEmployees) {
	for (int i = 0; i < numEmployees; i++) {
		int numPeriods;
		printf("Enter the number of evaluation periods for Employee[%d]: ", i + 1);
		scanf("%d", &numPeriods);
		employees[i]->ratings = (int*)malloc(numPeriods * sizeof(int));
		employees[i]->totalScore = 0;

		printf("Enter ratings for Employee[%d]:\n", i + 1);
		for (int j = 0; j < numPeriods; j++) {
			printf("Enter rating %d: ", j + 1);
			scanf("%d", &employees[i]->ratings[j]);

			if (employees[i]->ratings[j] < 1 || employees[i]->ratings[j] > 10) {
				printf("Invalid rating! Please enter a rating between 1 and 10.\n");
				j--;
			} else {
				employees[i]->totalScore += employees[i]->ratings[j];
			}
		}
	}
}

void displayPerformance(Employee **employees, int numEmployees) {
	for (int i = 0; i < numEmployees; i++) {
		printf("\nEmployee[%d] Performance:\n", i + 1);
		printf("Total Score: %d\n", employees[i]->totalScore);
		printf("Ratings: ");

		int numPeriods = 0;
		while (employees[i]->ratings[numPeriods] != '\0') numPeriods++;

		for (int j = 0; j < numPeriods; j++) {
			printf("%d ", employees[i]->ratings[j]);
		}
		printf("\n");
	}
}

int findEmployeeOfTheYear(Employee **employees, int numEmployees) {
	int maxScore = 0;
	int employeeIndex = -1;

	for (int i = 0; i < numEmployees; i++) {
		if (employees[i]->totalScore > maxScore) {
			maxScore = employees[i]->totalScore;
			employeeIndex = i;
		}
	}

	return employeeIndex;
}

int findHighestRatedPeriod(Employee **employees, int numEmployees) {
	int highestRatedPeriod = -1;
	int highestAverageRating = -1;

	for (int j = 0; j < numEmployees; j++) {
		int totalRatingForPeriod = 0;
		for (int i = 0; i < numEmployees; i++) {
			totalRatingForPeriod += employees[i]->ratings[j];
		}

		int averageRating = totalRatingForPeriod / numEmployees;
		if (averageRating > highestAverageRating) {
			highestAverageRating = averageRating;
			highestRatedPeriod = j;
		}
	}

	return highestRatedPeriod;
}

int findWorstPerformingEmployee(Employee **employees, int numEmployees) {
	int minScore = 999999;
	int employeeIndex = -1;

	for (int i = 0; i < numEmployees; i++) {
		if (employees[i]->totalScore < minScore) {
			minScore = employees[i]->totalScore;
			employeeIndex = i;
		}
	}

	return employeeIndex;
}

int main() {
	int numEmployees;

	printf("Enter the number of employees: ");
	scanf("%d", &numEmployees);

	Employee **employees = (Employee**)malloc(numEmployees * sizeof(Employee*));

	for (int i = 0; i < numEmployees; i++) {
		employees[i] = (Employee*)malloc(sizeof(Employee));
	}

	inputEmployees(employees, numEmployees);
	displayPerformance(employees, numEmployees);

	int employeeOfTheYear = findEmployeeOfTheYear(employees, numEmployees);
	printf("\nEmployee of the Year: Employee[%d] with Total Score: %d\n", employeeOfTheYear + 1, employees[employeeOfTheYear]->totalScore);

	int highestRatedPeriod = findHighestRatedPeriod(employees, numEmployees);
	printf("\nHighest Rated Period: %d\n", highestRatedPeriod + 1);

	int worstEmployee = findWorstPerformingEmployee(employees, numEmployees);
	printf("\nWorst Performing Employee: Employee[%d] with Total Score: %d\n", worstEmployee + 1, employees[worstEmployee]->totalScore);

	for (int i = 0; i < numEmployees; i++) {
		free(employees[i]->ratings);
		free(employees[i]);
	}
	free(employees);

	return 0;
}
