#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op, value;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}