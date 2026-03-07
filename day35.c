#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    int x;
    char op;

    while (scanf("%d", &x) == 1) {
        push(x);

        while (scanf(" %c", &op) == 1) {
            if (op=='+' || op=='-' || op=='*' || op=='/') {
                int b = pop();
                int a = pop();
                int res;

                if (op == '+') res = a + b;
                else if (op == '-') res = a - b;
                else if (op == '*') res = a * b;
                else res = a / b;

                push(res);
            } else {
                ungetc(op, stdin);
                break;
            }
        }
    }

    printf("%d", pop());
    return 0;
}