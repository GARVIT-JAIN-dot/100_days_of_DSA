/* Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int vertices;
    struct Node** adjList;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int u, int v, int type)
{
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    if (type == 2)
    {
        newNode = createNode(u);
        newNode->next = graph->adjList[v];
        graph->adjList[v] = newNode;
    }
}

void displayGraph(struct Graph* graph)
{
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%d -> ", i);

        struct Node* temp = graph->adjList[i];

        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int n, m, type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &type);

    printf("Enter %d edges (u v):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < n && v >= 0 && v < n)
            addEdge(graph, u, v, type);
        else
        {
            printf("Invalid edge!\n");
            i--;
        }
    }
    displayGraph(graph);

    return 0;
}