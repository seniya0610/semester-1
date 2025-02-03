#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUESTIONS 100

// Define a structure for a question
typedef struct {
    int qNum;        // Question number
    float timeTaken; // Time taken to answer in seconds
    int correct;     // 1 for correct, 0 for incorrect
} Question;

// Define a structure for a student
typedef struct {
    char name[MAX_NAME_LENGTH];  // Student's name
    int totalQues;               // Total number of questions attempted
    Question scorecard[MAX_QUESTIONS];  // Array of questions answered by the student
} Student;

// Function to input student details and scorecards
void getStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        // Input student name
        printf("Enter student name: ");
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove newline

        // Input the number of questions attempted by the student
        printf("Enter number of questions attempted: ");
        scanf("%d", &students[i].totalQues);
        getchar();  // Clear the newline character from the input buffer

        // Input the scorecard for each question
        for (int j = 0; j < students[i].totalQues; j++) {
            printf("Enter details for Question %d:\n", j + 1);

            // Question number
            students[i].scorecard[j].qNum = j + 1;

            // Answer time (in seconds)
            printf("Answer Time (in seconds): ");
            scanf("%f", &students[i].scorecard[j].timeTaken);

            // Correct or Incorrect answer
            printf("Is the answer correct? (1 for correct, 0 for incorrect): ");
            scanf("%d", &students[i].scorecard[j].correct);
        }
    }
}

// Function to calculate the total correct answers for a student
int getCorrect(Student student) {
    int correctAnswers = 0;
    for (int i = 0; i < student.totalQues; i++) {
        if (student.scorecard[i].correct) {
            correctAnswers++;
        }
    }
    return correctAnswers;
}

// Function to calculate the average time per correct answer
float getAvgTime(Student student) {
    int correctAnswers = 0;
    float totalTime = 0;

    for (int i = 0; i < student.totalQues; i++) {
        if (student.scorecard[i].correct) {
            correctAnswers++;
            totalTime += student.scorecard[i].timeTaken;
        }
    }

    if (correctAnswers == 0) {
        return 0;  // Avoid division by zero if no correct answers
    }

    return totalTime / correctAnswers;
}

// Function to find the fastest student (lowest average time)
Student getFastest(Student *students, int numStudents) {
    Student fastest = students[0];
    float fastestAvgTime = getAvgTime(fastest);

    for (int i = 1; i < numStudents; i++) {
        float avgTime = getAvgTime(students[i]);
        if (avgTime < fastestAvgTime) {
            fastest = students[i];
            fastestAvgTime = avgTime;
        }
    }

    return fastest;
}

// Function to rank students based on performance
void rankStudents(Student *students, int numStudents) {
    // Sort students by correct answers and then by average time
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            int correct1 = getCorrect(students[i]);
            int correct2 = getCorrect(students[j]);

            if (correct1 < correct2) {
                // Swap students
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            } else if (correct1 == correct2) {
                // If correct answers are equal, compare average time
                float avg1 = getAvgTime(students[i]);
                float avg2 = getAvgTime(students[j]);

                if (avg1 > avg2) {
                    // Swap to prioritize faster students
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    // Display ranked students
    printf("\n--- Student Rankings ---\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Rank %d: %s\n", i + 1, students[i].name);
        printf("Correct Answers: %d\n", getCorrect(students[i]));
        printf("Avg Time per Correct Answer: %.2f seconds\n\n", getAvgTime(students[i]));
    }
}

int main() {
    int numStudents;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  // Clear the newline character from the input buffer

    // Dynamically allocate memory for students
    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input details for students and their scorecards
    getStudents(students, numStudents);

    // Display performance for each student
    for (int i = 0; i < numStudents; i++) {
        int correctAnswers = getCorrect(students[i]);
        float avgTime = getAvgTime(students[i]);

        printf("\nStudent: %s\n", students[i].name);
        printf("Total Correct Answers: %d\n", correctAnswers);
        printf("Average Time per Correct Answer: %.2f seconds\n", avgTime);
    }

    // Find and display the fastest student (lowest average time per correct answer)
    Student fastestStudent = getFastest(students, numStudents);
    printf("\nThe fastest student is %s with an average time of %.2f seconds per correct answer.\n", 
           fastestStudent.name, getAvgTime(fastestStudent));

    // Rank students based on performance
    rankStudents(students, numStudents);

    // Free dynamically allocated memory
    free(students);

    return 0;
}
