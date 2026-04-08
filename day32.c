#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// push
void push(int val) {
    if(top < MAX - 1) {
        stack[++top] = val;
    }
}

// pop
void pop() {
    if(top >= 0) {
        top--;
    }
}

// display
void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, val;

    scanf("%d", &n);

    // push elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);

    // pop m times
    for(int i = 0; i < m; i++) {
        pop();
    }

    // print remaining stack
    display();

    return 0;
}
