#include <stdio.h>
#include <string.h>

typedef struct {
    char playerName[50];    
    int ballScores[12];     
    int totalScore;         
} Player;

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void playGame(Player *player) {
    printf("\n--- %s's Turn ---\n", player->playerName);
    player->totalScore = 0;

    for (int i = 0; i < 12; i++) {
        int score;
        printf("Enter score for ball %d (0-6): ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;  
        } else {
            printf("Invalid score! Ball marked with 0.\n");
            player->ballScores[i] = 0;
        }
    }
}

// Function to determine the winner
void findWinner(Player player1, Player player2) {
    printf("\n--- Match Result ---\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both scored %d runs.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(Player player1, Player player2) {
    printf("\n--- Match Scoreboard ---\n");

    printf("\n%s's Performance:\n", player1.playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player1.totalScore);
    printf("Average Score per Ball: %.2f\n", player1.totalScore / 12.0);

    printf("\n%s's Performance:\n", player2.playerName);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player2.totalScore);
    printf("Average Score per Ball: %.2f\n", player2.totalScore / 12.0);
}

int main() {
    Player player1, player2;

    printf("Enter Player 1's name: ");
    fgets(player1.playerName, 50, stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = '\0';  

    printf("Enter Player 2's name: ");
    fgets(player2.playerName, 50, stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = '\0';  

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
