/* Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS. */
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

void dfs(struct Node* adj[], int visited[], int stack[], int* top, int current)
{
    visited[current] = 1;

    struct Node* temp = adj[current];

    while (temp != NULL)
    {
        if (!visited[temp->vertex])
            dfs(adj, visited, stack, top, temp->vertex);

        temp = temp->next;
    }

    stack[++(*top)] = current;
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of directed edges: ");
    scanf("%d", &m);

    printf("Enter %d edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(adj, visited, stack, &top, i);
    }

    printf("Topological Order: ");

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}