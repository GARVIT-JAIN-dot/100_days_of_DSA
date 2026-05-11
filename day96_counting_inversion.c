/* Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j]. */
#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {

            temp[k++] = arr[i++];
        }
        else {

            temp[k++] = arr[j++];

            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right) {

    long long inversions = 0;

    if (left < right) {

        int mid = left + (right - left) / 2;

        inversions += mergeSort(arr, temp, left, mid);

        inversions += mergeSort(arr, temp, mid + 1, right);

        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversionCount =
        mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n",
           inversionCount);

    return 0;
}