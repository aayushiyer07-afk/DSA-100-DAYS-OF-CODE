#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = newNode;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    
    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    
    // Traverse together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head1, value);
    }
    
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        insert(&head2, value);
    }
    
    // Manually create intersection based on equal values
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    
    while (temp2 != NULL) {
        temp1 = head1;
        while (temp1 != NULL) {
            if (temp1->data == temp2->data) {
                temp2->next = temp1->next;
                break;
            }
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    
    struct Node* result = findIntersection(head1, head2);
    
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");
    
    return 0;
}