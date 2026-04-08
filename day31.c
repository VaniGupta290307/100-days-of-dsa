#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// push
void push(int val) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

// pop
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

// display
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, op, val;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &op);

        if(op == 1) {
            scanf("%d", &val);
            push(val);
        }
        else if(op == 2) {
            pop();
        }
        else if(op == 3) {
            display();
        }
    }

    return 0;
}
