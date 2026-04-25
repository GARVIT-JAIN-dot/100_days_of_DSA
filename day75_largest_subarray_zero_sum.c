/* Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray. */
#include <stdio.h>

int maxLen(int arr[], int n) {
    int prefix[1000], index[1000];
    int size = 0, sum = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            ans = i + 1;

        int found = 0;

        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                if (i - index[j] > ans)
                    ans = i - index[j];
                found = 1;
                break;
            }
        }

        if (!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLen(arr, n);

    printf("Length of longest zero sum subarray = %d\n", result);

    return 0;
}