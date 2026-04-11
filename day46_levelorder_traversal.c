/* Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node* arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree() {
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct Node* root = createNode(val);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &leftVal);

        if (leftVal != -1) {
            current->left = createNode(leftVal);
            enqueue(&q, current->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &rightVal);

        if (rightVal != -1) {
            current->right = createNode(rightVal);
            enqueue(&q, current->right);
        }
    }

    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("Level Order Traversal: ");

    while (!isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(&q, current->left);

        if (current->right)
            enqueue(&q, current->right);
    }
}

int main() {
    struct Node* root = buildTree();
    levelOrder(root);
    return 0;
}