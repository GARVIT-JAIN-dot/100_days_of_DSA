/* Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps. */
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main()
{
    int m, q;

    printf("Enter hash table size: ");
    scanf("%d", &m);

    int table[m];

    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    printf("Enter number of operations: ");
    scanf("%d", &q);

    while (q--)
    {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0)
        {
            int h = key % m;
            int inserted = 0;

            for (int i = 0; i < m; i++)
            {
                int index = (h + i * i) % m;

                if (table[index] == EMPTY)
                {
                    table[index] = key;
                    inserted = 1;
                    break;
                }
            }

            if (!inserted)
                printf("Table Full\n");
        }

        else if (strcmp(op, "SEARCH") == 0)
        {
            int h = key % m;
            int found = 0;

            for (int i = 0; i < m; i++)
            {
                int index = (h + i * i) % m;

                if (table[index] == EMPTY)
                    break;

                if (table[index] == key)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}