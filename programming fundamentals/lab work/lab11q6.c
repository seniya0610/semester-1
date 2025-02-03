#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char *file1, const char *file2, const char *outputFile) {
    
    FILE *srcFile1 = fopen(file1, "r");
    if (srcFile1 == NULL) {
        perror("Error opening first source file");
        return;
    }

    FILE *srcFile2 = fopen(file2, "r");
    if (srcFile2 == NULL) {
        perror("Error opening second source file");
        fclose(srcFile1);
        return;
    }

    FILE *destFile = fopen(outputFile, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile1);
        fclose(srcFile2);
        return;
    }

    char buffer[2048];
    
    // Copy contents of the first source file to the destination file
    while (fgets(buffer, sizeof(buffer), srcFile1)) {
        fputs(buffer, destFile);
    }

    // Copy contents of the second source file to the destination file
    while (fgets(buffer, sizeof(buffer), srcFile2)) {
        fputs(buffer, destFile);
    }

    printf("Contents of '%s' and '%s' have been merged into '%s'.\n", file1, file2, outputFile);

    // Clean up
    fclose(srcFile1);
    fclose(srcFile2);
    fclose(destFile);
}

int main() {
    char file1[100], file2[100], outputFile[100];

    printf("Enter the name of the first file: ");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';

    printf("Enter the name of the second file: ");
    fgets(file2, sizeof(file2), stdin);
    file2[strcspn(file2, "\n")] = '\0';

    printf("Enter the name of the output file: ");
    fgets(outputFile, sizeof(outputFile), stdin);
    outputFile[strcspn(outputFile, "\n")] = '\0';

    mergeFiles(file1, file2, outputFile);

    return 0;
}
