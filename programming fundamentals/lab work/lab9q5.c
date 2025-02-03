#include <stdio.h>

int countWords(char sentence[]) {
    int count = 0;
    int words = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    words = count + 1;

    if (sentence[0] == '\0' || sentence[0] == ' ') {
        return 0;
    }

    return words;
}

int main() {
    char sentence[1000];
    
    printf("Enter a sentence: ");
    
    fgets(sentence, sizeof(sentence), stdin);
    
    int wordCount = countWords(sentence);
    printf("Number of words in the sentence: %d\n", wordCount);

    return 0;
}
