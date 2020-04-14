/**
 * plurality.c
 *
 * Tim Haasnoot
 *
 * A code for plurality elections.
 */
 

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

// Array of candidates (alle kandidaten)
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

// Function to update vote totals given a new vote
bool vote(string name)
{
    // Loop over the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        // If found a match between name and vote, then update its vote count
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int total_votes = 0;

    // Find the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        // If found, then change the highest number of votes to that person and continue until the highest number of votes for a candidate is found
        if (candidates[i].votes > total_votes)
        {
            total_votes = candidates[i].votes;
        }
    }
    
    // When found, print out the name of the winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == total_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    
    // TODO end
    return;
}


