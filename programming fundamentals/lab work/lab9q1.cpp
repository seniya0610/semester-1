#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20];
    char revstr[5][20];

    printf("Enter 5 words:\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%19s", words[i]);
    }

    printf("Words entered:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            printf("%c ", words[i][j]);
        }
        printf("\n");
    }


    for (int i = 4; i >= 0; i--) {
        int length = strlen(words[i]);
        for (int j = 0; j < length; j++) {
            revstr[i][j] = words[i][length - 1 - j]; 
            printf("%c ", revstr[i][j]);
        }
        revstr[i][length] = '\0'; 
        printf("\n");
    }

    
    for (int i = 0; i < 5; i++) {
        if (strcmp(revstr[i], words[i]) == 0) {  
            printf("%s is a palindrome\n", words[i]);
        } else {
            printf("%s is not a palindrome\n", words[i]);
        }
    }

    return 0;
}
