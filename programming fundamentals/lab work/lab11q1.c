#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int ID;
} Manager;

typedef struct {
    char name[50];
    int ID;
    char department[30];
    Manager manager; 
    float salary;
} Employee;

void inputEmployees(Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);

        printf("Employee ID: ");
        scanf("%d", &employees[i].ID);

        printf("Department: ");
        scanf(" %[^\n]", employees[i].department);

        printf("Manager's Name: ");
        scanf(" %[^\n]", employees[i].manager.name);

        printf("Manager's ID: ");
        scanf("%d", &employees[i].manager.ID);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
}

// Function to display details of all employees
void displayEmployees(Employee employees[], int n) {
    printf("\nEmployee Details\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].ID);
        printf("Department: %s\n", employees[i].department);
        printf("Manager: %s (ID: %d)\n", employees[i].manager.name, employees[i].manager.ID);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}

void findHighestSalary(Employee employees[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (employees[i].salary > employees[index].salary) {
            index = i;
        }
    }
    printf("\nEmployee with Highest Salary\n");
    printf("Name: %s\n", employees[index].name);
    printf("Employee ID: %d\n", employees[index].ID);
    printf("Department: %s\n", employees[index].department);
    printf("Manager: %s (ID: %d)\n", employees[index].manager.name, employees[index].manager.ID);
    printf("Salary: %.2f\n", employees[index].salary);
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee employees[n];

    inputEmployees(employees, n);
    displayEmployees(employees, n);
    findHighestSalary(employees, n);

    return 0;
}



