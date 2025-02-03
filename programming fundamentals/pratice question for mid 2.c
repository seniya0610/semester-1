#include <stdio.h>

#define STUDENTS 5
#define LABS 9

int studentIDs[STUDENTS];
int marks[STUDENTS][LABS];

// Function prototypes
void PrintAllMarks(int studentID, int grid[STUDENTS][LABS + 1]);
void SetMarks(int grid[STUDENTS][LABS + 1]);
void PrintLabMax(int lab, int grid[STUDENTS][LABS + 1]);
void PrintLabAvg(int lab, int grid[STUDENTS][LABS + 1]);
void PrintLabMin(int lab, int grid[STUDENTS][LABS + 1]);
void PrintStdAvg(int studentID, int grid[STUDENTS][LABS + 1]);
void PrintGrid(int grid[STUDENTS][LABS + 1]);

int main() {
    int grid[STUDENTS][LABS + 1] = {0}; // Array to store student IDs and marks
    int stdID, choice;

    // Input student IDs
    for (int i = 0; i < STUDENTS; i++) {
        do {
            printf("Enter Student ID for student %d (6 digits): ", i + 1);
            scanf("%d", &stdID);
            if (stdID < 100000 || stdID > 999999) {
                printf("Error: Student ID must be a 6-digit number.\n");
            }
        } while (stdID < 100000 || stdID > 999999);
        
        grid[i][0] = stdID; // Store student ID
    }

    // Main menu loop
    do {
        printf("\nMenu:\n");
        printf("1. Set Marks\n");
        printf("2. Print Grid\n");
        printf("3. Print All Marks\n");
        printf("4. Print Lab Max\n");
        printf("5. Print Lab Avg\n");
        printf("6. Print Lab Min\n");
        printf("7. Print Student Avg\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                SetMarks(grid);
                break;
            case 2:
                PrintGrid(grid);
                break;
            case 3:
                printf("Enter Student ID to print all marks: ");
                scanf("%d", &stdID);
                PrintAllMarks(stdID, grid);
                break;
            case 4:
                printf("Enter Lab number (1-9) to find max: ");
                scanf("%d", &stdID);
                PrintLabMax(stdID, grid);
                break;
            case 5:
                printf("Enter Lab number (1-9) to find average: ");
                scanf("%d", &stdID);
                PrintLabAvg(stdID, grid);
                break;
            case 6:
                printf("Enter Lab number (1-9) to find min: ");
                scanf("%d", &stdID);
                PrintLabMin(stdID, grid);
                break;
            case 7:
                printf("Enter Student ID to find average: ");
                scanf("%d", &stdID);
                PrintStdAvg(stdID, grid);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Error: Invalid choice. Please try again.\n");
        }
    } while (choice != 8); // Continue until the user chooses to exit

    return 0;
}

// Function to input marks for a specific student and lab
void SetMarks(int grid[STUDENTS][LABS + 1]) {
    int stdID, labNumber, mark;

    while (1) {
        printf("Enter Student ID to update marks (or -1 to stop): ");
        scanf("%d", &stdID);
        
        if (stdID == -1) { // Allow user to stop entering marks
            break;
        }

        // Check if the student ID exists
        int found = 0;
        for (int i = 0; i < STUDENTS; i++) {
            if (stdID == grid[i][0]) {
                found = 1;

                // Ask for which lab's marks to update
                printf("Updating marks for Student ID %d:\n", stdID);
                printf("Enter Lab number (1-9) to update: ");
                scanf("%d", &labNumber);

                // Validate lab number
                if (labNumber < 1 || labNumber > LABS) {
                    printf("Error: Lab number must be between 1 and 9.\n");
                    continue; // Skip to next iteration if invalid
                }

                // Get the new marks for the specified lab
                do {
                    printf("Enter new Marks for Lab %d (1-10): ", labNumber);
                    scanf("%d", &mark);
                    if (mark < 1 || mark > 10) {
                        printf("Error: Marks must be between 1 and 10.\n");
                    }
                } while (mark < 1 || mark > 10);
                
                grid[i][labNumber] = mark; // Update marks in the grid
                printf("Marks updated successfully for Student ID %d in Lab %d.\n", stdID, labNumber);
                break; // Exit loop after updating marks
            }
        }
        
        if (!found) {
            printf("Error: Student ID %d does not exist.\n", stdID);
        }
    }
}

// Function to print the grid of student IDs and marks
void PrintGrid(int grid[STUDENTS][LABS + 1]) {
    printf("\nOutput Grid:\n");
    printf("%-10s", "ID"); // Print header for ID
    for (int j = 1; j <= LABS; j++) {
        printf("Lab %-7d", j); // Print header for each lab
    }
    printf("\n");

    for (int i = 0; i < STUDENTS; i++) {
        printf("%-10d", grid[i][0]); // Print student ID
        for (int j = 1; j <= LABS; j++) {
            printf("%-7d", grid[i][j]); // Print marks for each lab
        }
        printf("\n");
    }
}

// Function to print all marks for a specific student
void PrintAllMarks(int studentID, int grid[STUDENTS][LABS + 1]) {
    int found = 0;
    for (int i = 0; i < STUDENTS; i++) {
        if (grid[i][0] == studentID) {
            found = 1;
            printf("Marks for Student ID %d:\n", studentID);
            for (int j = 1; j <= LABS; j++) {
                printf("Lab %d: %d\n", j, grid[i][j]);
            }
            break;
        }
    }
    if (!found) {
        printf("Error: Student ID %d does not exist.\n", studentID);
    }
}

// Function to print the maximum marks for a specific lab
void PrintLabMax(int lab, int grid[STUDENTS][LABS + 1]) {
    // Validate lab number
    if (lab < 1 || lab > LABS) {
        printf("Error: Lab number must be between 1 and 9.\n");
        return;
    }

    int max = grid[0][lab]; // Initialize max with the first student's mark
    for (int i = 1; i < STUDENTS; i++) {
        if (grid[i][lab] > max) {
            max = grid[i][lab];
        }
    }
    printf("The maximum marks for Lab %d is: %d\n", lab, max);
}

// Function to print the average marks for a specific lab
void PrintLabAvg(int lab, int grid[STUDENTS][LABS + 1]) {
    // Validate lab number
    if (lab < 1 || lab > LABS) {
        printf("Error: Lab number must be between 1 and 9.\n");
        return;
    }

    int total = 0;
    for (int i = 0; i < STUDENTS; i++) {
        total += grid[i][lab];
    }
    float avg = (float)total / STUDENTS;
    printf("The average marks for Lab %d is: %.2f\n", lab, avg);
}

// Function to print the minimum marks for a specific lab
void PrintLabMin(int lab, int grid[STUDENTS][LABS + 1]) {
    // Validate lab number
    if (lab < 1 || lab > LABS) {
        printf("Error: Lab number must be between 1 and 9.\n");
        return;
    }

    int min = grid[0][lab]; // Initialize min with the first student's mark
    for (int i = 1; i < STUDENTS; i++) {
        if (grid[i][lab] < min) {
            min = grid[i][lab];
        }
    }
    printf("The minimum marks for Lab %d is: %d\n", lab, min);
}

// Function to print the average marks for a specific student
void PrintStdAvg(int studentID, int grid[STUDENTS][LABS + 1]) {
    int found = 0;
    for (int i = 0; i < STUDENTS; i++) {
        if (grid[i][0] == studentID) {
            found = 1;
            int total = 0;
            for (int j = 1; j <= LABS; j++) {
                total += grid[i][j];
            }
            float avg = (float)total / LABS;
            printf("The average marks for Student ID %d is: %.2f\n", studentID, avg);
            break;
        }
    }
    if (!found) {
        printf("Error: Student ID %d does not exist.\n", studentID);
    }
}
