#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11];
};

void assignValues(struct Employee *ptremp) {
    printf("Enter Employee Code: ");
    scanf("%d", ptremp->employeeCode);

    printf("Enter Employee Name: ");
    fgets(ptremp->employeeName, sizeof(ptremp->employeeName), stdin);

    size_t len = strlen(ptremp->employeeName);
    if (len > 0 && ptremp->employeeName[len - 1] == '\n') {
        ptremp->employeeName[len - 1] = '\0';
    }

    printf("Enter Date of Joining (YYYY-MM-DD): ");
    scanf("%s", ptremp->dateOfJoining);
}

void calculateTenure(struct Employee employees[], int count) {
    char currentDate[11];
    int currentYear, currentMonth, currentDay;
    int joinYear, joinMonth, joinDay;
    int moreThanThreeYearsCount = 0;

    // Ask user to enter the current date
    printf("Enter the current date (YYYY-MM-DD): ");
    scanf("%s", currentDate);
    sscanf(currentDate, "%d-%d-%d", &currentYear, &currentMonth, &currentDay);

    printf("\nEmployees with tenure more than 3 years:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        sscanf(employees[i].dateOfJoining, "%d-%d-%d", &joinYear, &joinMonth, &joinDay);

        int tenureYears = currentYear - joinYear;
        if (currentMonth < joinMonth || (currentMonth == joinMonth && currentDay < joinDay)) {
            tenureYears--; 
        }
        if (tenureYears > 3) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %s\n", employees[i].dateOfJoining);
            printf("Tenure: %d years\n\n", tenureYears);
            moreThanThreeYearsCount++;
        }
    }

    printf("Total employees with tenure more than 3 years: %d\n", moreThanThreeYearsCount);
}

int main() {
    struct Employee employees[4];

    printf("Enter details for 4 employees:\n");
    for (int i = 0; i < 4; i++) {
        printf("\nEmployee %d:\n", i + 1);
        assignValues(&employees[i]);
    }

    calculateTenure(employees, 4);

    return 0;
}
