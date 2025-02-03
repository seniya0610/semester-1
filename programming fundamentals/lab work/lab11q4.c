#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int characters = 0, words = 0, lines = 0;
    int inWord = 0; 
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        characters++;  // Count every character

        if (ch == '\n') {
            lines++;  // Increment line count on encountering a newline character
        }

        if (isspace(ch)) {
            inWord = 0;  // We are no longer in a word
        } else {
            if (inWord == 0) {
                words++;  // Start of a new word
                inWord = 1;  // Now we are inside a word
            }
        }
    }

    fclose(file);

    printf("Total characters: %d\n", characters);
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);
}

int main() {
    char filename[100];

    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove the newline character if it is included by fgets
    filename[strcspn(filename, "\n")] = '\0';

    countFileContent(filename);

    return 0;
}
