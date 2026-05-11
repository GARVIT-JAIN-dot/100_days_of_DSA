/* Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous. */
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

int main() {

    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    printf("\nMerged Intervals:\n");

    int start = arr[0].start;
    int end = arr[0].end;

    for (int i = 1; i < n; i++) {

        if (arr[i].start <= end) {

            if (arr[i].end > end)
                end = arr[i].end;
        }
        else {

            printf("[%d, %d]\n", start, end);

            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("[%d, %d]\n", start, end);

    return 0;
}