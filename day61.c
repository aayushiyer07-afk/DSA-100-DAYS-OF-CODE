#include <stdio.h>

int main() {
    int n, m;
    
    // Input number of vertices and edges
    scanf("%d %d", &n, &m);
    
    int adj[n][n];

    // Initialize matrix with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int type;
    // 0 for undirected, 1 for directed
    scanf("%d", &type);

    int u, v;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(type == 0) {  // undirected
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}