#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;  // Increase indegree of v
    }

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], k = 0;

    while (!isEmpty()) {
        int node = dequeue();
        topo[k++] = node;

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Check for cycle
    if (k != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}