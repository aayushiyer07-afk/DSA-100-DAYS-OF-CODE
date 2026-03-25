#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node, int hd) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    struct QNode temp = q->arr[q->front];
    q->front++;
    return temp;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct QNode temp = dequeue(q);
        struct Node* curr = temp.node;

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // HD range assumption
    int minHD = -1000, maxHD = 1000;
    int offset = 1000;

    // Array of lists
    int result[2001][100];
    int count[2001] = {0};

    struct Queue* q = createQueue(1000);
    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        result[index][count[index]++] = node->data;

        if (node->left)
            enqueue(q, node->left, hd - 1);

        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2001; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}