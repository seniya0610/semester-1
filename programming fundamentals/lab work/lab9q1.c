#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    char reversed[21];
    int length = strlen(str);

    for (int i = length, j = 0; i > 0; i--, j++) {
        reversed[j] = str[i - 1];
    }
    reversed[length] = '\0';

    if (strcmp(str, reversed) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int numWords = 5;
    char words[5][21];

    printf("Enter 5 words (max length 20 characters each):\n");
    for (int i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        scanf("%20s", words[i]);
    }

    printf("\nPalindrome check:\n");
    for (int i = 0; i < numWords; i++) {
        if (isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }

    return 0;
}
