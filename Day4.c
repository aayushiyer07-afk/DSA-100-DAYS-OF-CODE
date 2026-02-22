// Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>
int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d integers separated by spaces: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int start = 0, end = n - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
    printf("Reversed array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
