#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};  // For lowercase letters

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            // Second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }

        freq[index]++;
    }

    // If no repeated character
    printf("-1\n");

    return 0;
}