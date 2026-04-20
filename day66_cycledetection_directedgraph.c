#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

int dfs(struct Node* adj[], int visited[], int recStack[], int current)
{
    visited[current] = 1;
    recStack[current] = 1;

    struct Node* temp = adj[current];

    while (temp != NULL)
    {
        int next = temp->vertex;

        if (!visited[next])
        {
            if (dfs(adj, visited, recStack, next))
                return 1;
        }
        else if (recStack[next])
        {
            return 1; // back edge found
        }

        temp = temp->next;
    }

    recStack[current] = 0;
    return 0;
}

int hasCycle(struct Node* adj[], int n)
{
    int visited[n], recStack[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, visited, recStack, i))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter %d directed edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(adj, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}