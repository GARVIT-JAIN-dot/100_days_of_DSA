/* Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix */
#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int choice;
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);

    printf("Enter %d edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
        {
            graph[u][v] = 1;

            if (choice == 2)
                graph[v][u] = 1;
        }
        else
        {
            printf("Invalid edge: %d %d\n", u, v);
            i--;
        }
    }

    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);

        printf("\n");
    }

    return 0;
}