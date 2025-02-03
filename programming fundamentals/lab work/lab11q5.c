#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseFileContent(const char *sourceFile, const char *destFile) {
    FILE *srcFile = fopen(sourceFile, "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    fseek(srcFile, 0, SEEK_END);
    long fileSize = ftell(srcFile);
    rewind(srcFile);

    char *buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        fclose(srcFile);
        return;
    }

    fread(buffer, 1, fileSize, srcFile);
    buffer[fileSize] = '\0';

    FILE *destFilePtr = fopen(destFile, "w+");
    if (destFilePtr == NULL) {
        perror("Error opening destination file");
        free(buffer);
        fclose(srcFile);
        return;
    }

    // Write the content in reverse to the destination file
    for (long i = fileSize - 1; i >= 0; i--) {
        fputc(buffer[i], destFilePtr);
    }

    // Clean up
    printf("Content reversed and saved to %s\n", destFile);
    free(buffer);
    fclose(srcFile);
    fclose(destFilePtr);
}

int main() {
    char sourceFile[100], destFile[100];

    printf("Enter source file name: ");
    fgets(sourceFile, sizeof(sourceFile), stdin);
    sourceFile[strcspn(sourceFile, "\n")] = '\0';

    printf("Enter destination file name: ");
    fgets(destFile, sizeof(destFile), stdin);
    destFile[strcspn(destFile, "\n")] = '\0';

    reverseFileContent(sourceFile, destFile);

    return 0;
}
