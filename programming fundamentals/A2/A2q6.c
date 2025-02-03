#include <stdio.h>

int sticksGame(int totalSticks) {
    if (totalSticks % 5 == 0) {
        return 0;
    } else {
        return totalSticks % 5;
    }
}

void main() {
    int outcome, stickCount;
    printf("Enter the total number of sticks: ");
    scanf("%d", &stickCount);

    outcome = sticksGame(stickCount);

    if (outcome == 0) {
        printf("Impossible to win\n");
    } else {
        printf("You need to pick %d in the first turn to win\n", outcome);
    }
}
