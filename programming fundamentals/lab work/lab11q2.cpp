#include <stdio.h>
#include <stdlib.h>

void WriteToFile(const char *filename) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    char input[1024];

    printf("Enter text you want to write to the file: ");
    fgets(input, sizeof(input), stdin);  
    fprintf(fptr, "%s", input);  

    fclose(fptr); 
}

void AppendToFile(const char *filename) {
    FILE *fptr = fopen(filename, "a");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    char input[1024];

    printf("Enter data to append: ");
    fgets(input, sizeof(input), stdin);  
    fprintf(fptr, "%s", input);  

    fclose(fptr); 
}

void ReadFile(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    
    while (fgets(buffer, sizeof(buffer), fptr)) {
        printf("%s", buffer);  
    }

    if (feof(fptr)) {
        printf("\nEnd of file reached.\n");
    } else if (ferror(fptr)) {
        printf("An error occurred while reading the file.\n");
    }

    fclose(fptr); 
}

int main() {
    char fileName[100];
    int choice;

    printf("Enter file name: ");
    scanf("%s", fileName);  
    getchar(); 

    while (1) {
        printf("\nMenu:\n");
        printf("1. Write\n");
        printf("2. Append\n");
        printf("3. Read\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            WriteToFile(fileName);  
            break;
        case 2:
            AppendToFile(fileName);  
            break;
        case 3:
            ReadFile(fileName);  
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);  
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
