#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text); //Function to count letters
int count_words(string text); //Function to count words
int count_sentences(string text); //Function to count sentences

int main(void)
{
    string text = get_string("Get text: "); //Get text from the user

    //Store the amount of letters, sentences and word in variables
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text);

    //Calculate Coleman-Liau index
    float index = ((0.0588 * (letters * 100) / (float) words) - (0.296 * (sentences * 100) / (float) words) - 15.8);

    //Index less than 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    //Index between 1 and 16
    if (index >= 1 && index < 16)
    {
        printf("Grade %.0f\n", round(index));
    }

    //Index greater than or equal to 16
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int l_counter = 0;

    //If the character is a letter, adds 1 to counter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            l_counter += 1;
        }

    }

    return l_counter;
}

int count_words(string text)
{
    int w_counter = 0;

    //Adds 1 to counter each space
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            w_counter += 1;
        }
    }
    //Adds a last 1 for the last word without a space after it
    w_counter += 1;

    return w_counter;
}

int count_sentences(string text)
{
    int s_counter = 0;

    //Adds 1 to counter for each dot, question mark or exclamation point
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s_counter += 1;
        }

    }

    return s_counter;
}
