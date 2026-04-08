#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

// push
void push(char x) {
    stack[++top] = x;
}

// pop
char pop() {
    return stack[top--];
}

// precedence
int prec(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, k = 0;

    scanf("%s", infix);

    while(infix[i] != '\0') {

        // operand
        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // opening bracket
        else if(infix[i] == '(') {
            push(infix[i]);
        }

        // closing bracket
        else if(infix[i] == ')') {
            while(stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }

        // operator
        else {
            while(top != -1 && prec(stack[top]) >= prec(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // pop remaining
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}
