#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet in a 2D array
int POINTS[2][26] = {
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
    {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}
};

int compute_score(string word);

int main(void)
{
    // Ask both players for a word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate the score for each player's word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Assign the winner based on scores
    string winner;
    if (score1 > score2) {
        winner = "Player 1 wins!";
    } else if (score2 > score1) {
        winner = "Player 2 wins!";
    } else {
        winner = "Tie!";
    }
    
    // Print out the winner
    printf("%s\n", winner);
}

int compute_score(string word)
{
    int score = 0;
    int n = strlen(word);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) {
            if (tolower(word[i]) == POINTS[0][j]) {
                score += POINTS[1][j];
            }
        }
    }
    return score;
}