/* Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate. */
#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {

        newNode->next = *head;
        *head = newNode;

        return;
    }

    struct Node* current = *head;

    while (current->next != NULL &&
           current->next->data < value) {

        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {

    struct Node* buckets[BUCKETS];

    for (int i = 0; i < BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {

        int index = arr[i] * BUCKETS;

        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < BUCKETS; i++) {

        struct Node* temp = buckets[i];

        while (temp != NULL) {

            arr[k++] = temp->data;

            temp = temp->next;
        }
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d real numbers in range [0,1):\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}