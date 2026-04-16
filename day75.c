#include <stdio.h>

#define MAX 1000

int main() {
    int n, arr[MAX];
    
    // Input size
    scanf("%d", &n);
    
    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Hash array (to store first occurrence of sum)
    int hash[2 * MAX];
    
    // Initialize hash array with -1
    for(int i = 0; i < 2 * MAX; i++) {
        hash[i] = -1;
    }

    int offset = MAX;  // to handle negative sums

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if(sum == 0) {
            maxLen = i + 1;
        }

        // Case 2: sum seen before
        if(hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if(len > maxLen) {
                maxLen = len;
            }
        } else {
            // store first occurrence
            hash[sum + offset] = i;
        }
    }

    // Output result
    printf("%d", maxLen);

    return 0;
}