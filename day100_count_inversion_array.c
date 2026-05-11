/* Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT). */
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int index;
};

void merge(struct Item arr[], int left, int mid, int right,
           int count[]) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Item L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    int rightCount = 0;

    while (i < n1 && j < n2) {

        if (R[j].value < L[i].value) {

            arr[k++] = R[j++];
            rightCount++;
        }
        else {

            count[L[i].index] += rightCount;

            arr[k++] = L[i++];
        }
    }

    while (i < n1) {

        count[L[i].index] += rightCount;

        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(struct Item arr[], int left,
               int right, int count[]) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, count);

        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    struct Item arr[n];
    int count[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &nums[i]);

        arr[i].value = nums[i];
        arr[i].index = i;

        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Count of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}