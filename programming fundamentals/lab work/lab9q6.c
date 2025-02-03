#include <stdio.h>
#include <string.h>

int areRotations(char s1[], char s2[]) {
    int n = strlen(s1);

    if (n != strlen(s2)) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (strcmp(s1, s2) == 0) {
            return 1; 
        }

        char last = s1[n - 1];
        for (int j = n - 1; j > 0; j--) {
            s1[j] = s1[j - 1];
        }
        s1[0] = last;
    }
    return 0;
}

int main() {
    char s1[] = "aab";
    char s2[] = "aba";

    printf("%s\n", areRotations(s1, s2) ? "true" : "false");

    return 0;
}
