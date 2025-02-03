#include <stdio.h>
#include <stdlib.h>

int main() {
    int std, grade;
    int **Arraystd;

    // Input number of students
    printf("Number of students: ");
    scanf("%d", &std);

    //rows
    Arraystd = (int **)malloc(std * sizeof(int *));
    for (int i = 0; i < std; i++) {
        //columns
        printf("Number of grades for student[%d]: ", i+1);
        scanf("%d", &grade);

        Arraystd[i] = (int *)malloc(grade * sizeof(int));

        // Input grades for this student
        for (int j = 0; j < grade; j++) {
            printf("Enter grade %d for student[%d]: ", j + 1, i + 1);
            scanf("%d", &Arraystd[i][j]);
        }
    }

    printf("\nGrades:\n");
    for (int i = 0; i < std; i++) {
        printf("Student[%d]: ", i);
        for (int j = 0; Arraystd[i][j] != '\0'; j++) {
            printf("%d ", Arraystd[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < std; i++) {
        free(Arraystd[i]);
    }
    free(Arraystd);

    return 0;
}
