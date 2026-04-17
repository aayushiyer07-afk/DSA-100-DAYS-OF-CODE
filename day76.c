#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int n;

// DFS function
void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int m, u, v;
    
    // Input number of nodes and edges
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    int components = 0;

    // Count connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    // Output result
    printf("%d\n", components);

    return 0;
}