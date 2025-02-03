#include <stdio.h>
#include <string.h>

void compress(char word[3][50]);

int main() {
    char word[3][50];
    for (int j = 0; j < 3; j++) {
        printf("Enter your word: ");
        scanf("%s", word[j]);
    }    
    compress(word);
    
    return 0;
}

void compress(char word[3][50]) {
    for (int k = 0; k < 3; k++) {
        int j = 0; // Reset j for each word
        for (int i = 0; word[k][i] != '\0'; i++) {
            if (word[k][i] != word[k][i + 1]) {
                word[k][j++] = word[k][i];
            }
        }
        word[k][j] = '\0';
        puts(word[k]);
    }        
}
