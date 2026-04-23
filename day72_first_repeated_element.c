/* Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e */
#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int freq[26] = {0};
    int found = 0;

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++)
    {
        int index = s[i] - 'a';

        freq[index]++;

        if (freq[index] == 2)
        {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("-1\n");

    return 0;
}