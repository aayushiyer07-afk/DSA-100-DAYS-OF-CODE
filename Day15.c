//Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.


#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    // Check if square matrix
    if(m == n) {
        for(int i = 0; i < m; i++) {
            sum += matrix[i][i];
        }
        printf("%d", sum);
    } else {
        printf("Primary diagonal not possible");
    }

    return 0;
}