/* Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    printf("\nTracing path to LCA:\n");

    while (root != NULL) {
        printf("At node: %d\n", root->val);

        if (p < root->val && q < root->val) {
            printf("Both nodes are smaller\n");
            root = root->left;
        } 
        else if (p > root->val && q > root->val) {
            printf("Both nodes are larger\n");
            root = root->right;
        } 
        else {
            printf("This is the LCA!\n");
            return root;
        }
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct TreeNode* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values to insert into BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two node values (p and q): ");
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("\nLowest Common Ancestor: %d\n", lca->val);
    else
        printf("LCA not found.\n");

    return 0;
}