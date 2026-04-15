#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];

    // Input votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char candidates[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], candidates[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(candidates[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = count[0];
    char winner[NAME_LEN];
    strcpy(winner, candidates[0]);

    for (int i = 1; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, candidates[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(candidates[i], winner) < 0) {
                strcpy(winner, candidates[i]);
            }
        }
    }

    // Output result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}