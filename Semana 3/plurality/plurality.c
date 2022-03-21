#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //This loop uses the function String Compare to check if the name of the candidate is valid.
    //In case it is, it updates the total of votes. In case it isn't, the return 0 prints "invalid vote"
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return 1;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string winner = candidates[0].name; //Saves winner as the first name in the array
    int winner_votes = candidates[0].votes; //Saves the amount of votes as the first amount in the array

    //This loop will check tha amount of votes of each candidate and compare to the next one in the array
    for (int i = 0; i < candidate_count - 1; i++)
    {
        //If the amount of votes is bigger than the candidate before, it updates the name ane votes of the winner
        if (candidates[i].votes < candidates[i + 1].votes)
        {
            winner = candidates[i + 1].name;
            winner_votes = candidates[i + 1].votes;
        }
    }

    //After passing through all the candidates it checks the ones with the same amount of votes as the winner and prints their names
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
