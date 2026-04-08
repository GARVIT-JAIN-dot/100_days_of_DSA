/* Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    struct Queue* q = createQueue();

    printf("Enter operations (ENQUEUE x / DEQUEUE):\n");

    for (int i = 0; i < n; i++) {
    char op[10];
    scanf("%s", op);

    if (op[0] == 'E') { 
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    } 
    else if (op[0] == 'D' && op[1] == 'E') {  
        printf("%d\n", dequeue(q));
    }
    else if (op[0] == 'D') {
        display(q);
    }
    }

    return 0;
}