/* Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner. */
#include <stdio.h>
#include <string.h>

struct Candidate
{
    char name[50];
    int votes;
};

int main()
{
    int n;
    
    printf("Enter number of votes: ");
    scanf("%d", &n);

    struct Candidate c[100];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        char vote[50];
        scanf("%s", vote);

        int found = 0;

        for (int j = 0; j < count; j++)
        {
            if (strcmp(c[j].name, vote) == 0)
            {
                c[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            strcpy(c[count].name, vote);
            c[count].votes = 1;
            count++;
        }
    }

    char winner[50];
    int maxVotes = -1;

    for (int i = 0; i < count; i++)
    {
        if (c[i].votes > maxVotes)
        {
            maxVotes = c[i].votes;
            strcpy(winner, c[i].name);
        }
        else if (c[i].votes == maxVotes)
        {
            if (strcmp(c[i].name, winner) < 0)
                strcpy(winner, c[i].name);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}