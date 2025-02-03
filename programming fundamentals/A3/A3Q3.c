#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email) {
    if (email == NULL || strlen(email) == 0) {
        return 0; 
    }

    char *atSymbol = strchr(email, '@');
    if (atSymbol == NULL) {
        return 0; 
    }

    if (strchr(atSymbol + 1, '@') != NULL) {
        return 0;
    }

    char *dotAfterAt = strchr(atSymbol, '.');
    if (dotAfterAt == NULL) {
        return 0;
    }

    return 1;
}

int main() {
    char *email;
    size_t bufferSize = 100;

    email = (char *)malloc(bufferSize * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter an email address: ");
    if (fgets(email, bufferSize, stdin) == NULL) {
        printf("Error reading input.\n");
        free(email);
        return 1;
    }

    email[strcspn(email, "\n")] = '\0';

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}
