#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree from inorder and postorder
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if(start > end)
        return NULL;

    // Last element of postorder is root
    int rootValue = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(rootValue);

    // If only one element
    if(start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, rootValue);

    // IMPORTANT: build right subtree first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal (Root Left Right)
void preorder(struct Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Main function
int main() {
    int n;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Print preorder traversal
    preorder(root);

    return 0;
}