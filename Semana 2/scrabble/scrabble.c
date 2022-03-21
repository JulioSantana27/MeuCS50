#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);

int main(void)
{
    //Prompt the user for the words
    string word1 = get_string("Player 1: \n");
    string word2 = get_string("Player 2: \n");

    //Compute the points for each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }

    if (score1 < score2)
    {
        printf("Player 2 wins!");
    }

    if (score1 == score2)
    {
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(string word)
{
    int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    //Array to compare to POINTS when scoring
    char ALPHABET[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int score = 0;

    for (int i = 0, n = strlen(word); i < n ; i++) //Loop to chech each letter in the word
    {
        if (isupper(word[i])) //If the letter is uppercase, converts to lowercase
        {
            word[i] = tolower(word[i]);
        }

        if (word[i] >= 'a' && word[i] <= 'z') //Give 0 points to characters that are not letters
        {
            score += 0;
        }

        for (int k = 0; k < 27; k++) //Loop to check each letter in ALPHABET and give a score
        {
            if (ALPHABET[k] == word[i])
            {
                score += POINTS[k];
            }
        }
    }

    return score;
}
