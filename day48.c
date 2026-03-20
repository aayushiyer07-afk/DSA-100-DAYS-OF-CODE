#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    // Base case: empty tree
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recur for left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}