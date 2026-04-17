/* Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together 
from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear;
    struct QNode arr[1000];
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q).node;

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    int map[200][100];  // store nodes
    int count[200] = {0};

    int minHD = 0, maxHD = 0;

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        map[hd + 100][count[hd + 100]++] = curr->data;

        if (curr->left)
            enqueue(&q, curr->left, hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }

    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + 100]; j++) {
            printf("%d ", map[i + 100][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nVertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}