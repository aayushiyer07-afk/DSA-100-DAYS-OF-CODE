#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order
struct Queue {
    int front, rear;
    int size;
    struct Node** array;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->array[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q))
        return NULL;

    struct Node* temp = q->array[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Build tree in level order
struct Node* buildTree() {
    int data;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);
    struct Queue* q = createQueue(100);

    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);

        // Left child
        printf("Enter left child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &data);
        if (data != -1) {
            temp->left = createNode(data);
            enqueue(q, temp->left);
        }

        // Right child
        printf("Enter right child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &data);
        if (data != -1) {
            temp->right = createNode(data);
            enqueue(q, temp->right);
        }
    }

    return root;
}

// Level order traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(q, temp->left);
        if (temp->right)
            enqueue(q, temp->right);
    }
}

// Mirror the tree
void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Main function
int main() {
    struct Node* root = buildTree();

    printf("\nLevel Order of Original Tree:\n");
    levelOrder(root);

    mirrorTree(root);

    printf("\nLevel Order of Mirror Tree:\n");
    levelOrder(root);

    return 0;
}