/* Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output. */

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {

    int max = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    int output[n];

    for (int i = n - 1; i >= 0; i--) {

        output[count[arr[i]] - 1] = arr[i];

        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d non-negative integers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}