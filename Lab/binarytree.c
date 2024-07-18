#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add distances to an array and return the number of good pairs
int dfs(TreeNode* node, int distance, int* count) {
    if (!node) return 0;
    
    if (!node->left && !node->right) {
        int *distances = (int *)malloc(sizeof(int) * distance);
        for (int i = 0; i < distance; i++) distances[i] = 0;
        distances[0] = 1;
        return distances;
    }

    int *leftDistances = dfs(node->left, distance, count);
    int *rightDistances = dfs(node->right, distance, count);

    for (int i = 0; i < distance; i++) {
        for (int j = 0; j < distance; j++) {
            if (i + j + 2 <= distance) {
                *count += leftDistances[i] * rightDistances[j];
            }
        }
    }

    int *distances = (int *)malloc(sizeof(int) * distance);
    for (int i = 0; i < distance; i++) distances[i] = 0;
    for (int i = 0; i < distance - 1; i++) {
        distances[i + 1] = leftDistances[i] + rightDistances[i];
    }

    free(leftDistances);
    free(rightDistances);

    return distances;
}

int countPairs(TreeNode* root, int distance) {
    int count = 0;
    dfs(root, distance, &count);
    return count;
}

int main() {
    // Example tree:
    //     1
    //    / \
    //   2   3
    //  /   / \
    // 4   5   6
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);

    int distance = 3;
    int result = countPairs(root, distance);
    printf("Number of good leaf node pairs: %d\n", result);

    // Free the allocated memory (not shown for simplicity)
    return 0;
}
