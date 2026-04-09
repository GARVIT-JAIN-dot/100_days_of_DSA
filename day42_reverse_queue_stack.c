/* Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    printf("Reversed queue:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    free(queue);
    free(stack);

    return 0;
}