#include <stdio.h>

int main() {

    int count[27] = {0};  // Extra index for space
    char slogan[20];

    printf("Enter slogan: ");
    scanf(" %[^\n]", slogan);

    // Count each character
    for (int i = 0; slogan[i] != '\0'; ++i) {
        if (slogan[i] == ' ') {
            count[26] += 1;  // Use index 26 for space
        } else if (slogan[i] >= 'A' && slogan[i] <= 'Z') {
            slogan[i] = slogan[i] + 32;  // Convert to lowercase
            count[slogan[i] - 'a'] += 1;
        } else if (slogan[i] >= 'a' && slogan[i] <= 'z') {
            count[slogan[i] - 'a'] += 1;
        }
    }

    // Print the results
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            printf("[%c, %d]\n", 'a' + i - 32, count[i]);
        }
    }
    if (count[26] > 0) {
        printf("[space, %d]\n", count[26]);
    }

    return 0;
}
