#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CopyFile(const char *sourceFile, const char *destFile) {
    FILE *source = fopen(sourceFile, "r");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destFile, "w+");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(dest);
}

int main() {
    char sourceFile[100], destFile[100];

    printf("Enter the source file name: ");
    fgets(sourceFile, sizeof(sourceFile), stdin);
    sourceFile[strcspn(sourceFile, "\n")] = '\0';  // Remove newline character

    printf("Enter the destination file name: ");
    fgets(destFile, sizeof(destFile), stdin);
    destFile[strcspn(destFile, "\n")] = '\0';  // Remove newline character

    CopyFile(sourceFile, destFile);

    return 0;
}
