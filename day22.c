#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("%d\n", countNodes(head));

    return 0;
}