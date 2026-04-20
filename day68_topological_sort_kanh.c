/* Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm). */
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

void topologicalSort(struct Node* adj[], int n)
{
    int indegree[n];
    int queue[n];
    int front = 0, rear = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < n; i++)
    {
        struct Node* temp = adj[i];

        while (temp != NULL)
        {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological Order: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);
        count++;

        struct Node* temp = adj[current];

        while (temp != NULL)
        {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                queue[rear++] = temp->vertex;

            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle detected. Topological sort not possible.");

    printf("\n");
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

    topologicalSort(adj, n);

    return 0;
}