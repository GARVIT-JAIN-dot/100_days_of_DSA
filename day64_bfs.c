/* Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order */
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

    newNode = createNode(u);   // undirected graph
    newNode->next = adj[v];
    adj[v] = newNode;
}

void bfs(struct Node* adj[], int n, int start)
{
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];

        while (temp != NULL)
        {
            int next = temp->vertex;

            if (!visited[next])
            {
                visited[next] = 1;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }
}

int main()
{
    int n, m, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter %d edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    bfs(adj, n, s);

    return 0;
}