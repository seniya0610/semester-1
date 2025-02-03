#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[n][100];
    int grouped[n];

    for (int i = 0; i < n; i++) {
        grouped[i] = 0; 
    }

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    printf("Grouped Anagrams:\n");

    for (int i = 0; i < n; i++) {
        if (grouped[i] == 1) continue;

        printf("[");
        grouped[i] = 1;

        int count[26] = {0};
        for (int k = 0; words[i][k] != '\0'; k++) {
            count[words[i][k] - 'a']++;
        }

        printf("'%s'", words[i]);

        for (int j = i + 1; j < n; j++) {
            if (grouped[j] == 0) {
                int temp_count[26] = {0};

                for (int k = 0; words[j][k] != '\0'; k++) {
                    temp_count[words[j][k] - 'a']++;
                }

                int is_anagram = 1;
                for (int k = 0; k < 26; k++) {
                    if (count[k] != temp_count[k]) {
                        is_anagram = 0;
                        break;
                    }
                }

                if (is_anagram) {
                    printf(", '%s'", words[j]);
                    grouped[j] = 1;
                }
            }
        }
        printf("]\n");
    }

    return 0;
}
