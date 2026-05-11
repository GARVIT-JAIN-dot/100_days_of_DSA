/* Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times. */
#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start;
    int end;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;

    return m1->start - m2->start;
}

void heapifyUp(int heap[], int index) {

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {

    while (1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }
}

void push(int heap[], int *size, int value) {

    heap[*size] = value;

    heapifyUp(heap, *size);

    (*size)++;
}

void pop(int heap[], int *size) {

    heap[0] = heap[*size - 1];

    (*size)--;

    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Meeting meetings[n];

    printf("Enter meeting intervals (start end):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &meetings[i].start,
              &meetings[i].end);
    }

    qsort(meetings, n,
          sizeof(struct Meeting),
          compare);

    int heap[n];
    int heapSize = 0;

    push(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {

        if (meetings[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }

        push(heap, &heapSize, meetings[i].end);
    }

    printf("Minimum meeting rooms required: %d\n",
           heapSize);

    return 0;
}