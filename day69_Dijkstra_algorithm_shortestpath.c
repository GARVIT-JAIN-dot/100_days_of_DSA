/* Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node
{
    int vertex, weight;
    struct Node* next;
};

struct HeapNode
{
    int vertex, dist;
};
struct Node* graph[MAX];

struct Node* createNode(int v, int w)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w)
{
    struct Node* newNode = createNode(v, w);
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = graph[v];
    graph[v] = newNode;
}
void swap(struct HeapNode* a, struct HeapNode* b)
{
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(struct HeapNode heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent].dist > heap[index].dist)
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

void heapifyDown(struct HeapNode heap[], int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(struct HeapNode heap[], int* size, int v, int d)
{
    heap[*size].vertex = v;
    heap[*size].dist = d;
    heapifyUp(heap, *size);
    (*size)++;
}

struct HeapNode pop(struct HeapNode heap[], int* size)
{
    struct HeapNode root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);
    return root;
}

void dijkstra(int n, int source)
{
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct HeapNode heap[1000];
    int heapSize = 0;

    dist[source] = 0;
    push(heap, &heapSize, source, 0);

    while (heapSize > 0)
    {
        struct HeapNode current = pop(heap, &heapSize);
        int u = current.vertex;

        if (visited[u])
            continue;

        visited[u] = 1;

        struct Node* temp = graph[u];

        while (temp != NULL)
        {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(heap, &heapSize, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", i, dist[i]);
}

int main()
{
    int n, m, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        graph[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter %d edges (u v weight):\n", m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}