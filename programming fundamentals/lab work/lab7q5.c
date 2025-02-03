#include <stdio.h>

int main() {
    for (int i = 0; i <= 6; i++) {
        if (i % 2 == 0) {
            printf("%d          %d          %d\n", i, i, i);
        } else {
            printf("           %d\n", i);
        }
    }
    return 0;
}
