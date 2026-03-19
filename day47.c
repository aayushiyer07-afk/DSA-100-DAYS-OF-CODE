#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to calculate height
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}