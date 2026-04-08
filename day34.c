#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// stack node
struct node {
    int data;
    struct node* next;
};

// push
struct node* push(struct node* top, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

// pop
int pop(struct node** top) {
    if(*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// evaluate postfix
int evaluate(char* exp) {
    struct node* top = NULL;
    int i = 0;

    while(exp[i] != '\0') {

        // skip spaces
        if(exp[i] == ' ') {
            i++;
            continue;
        }

        // operand
        if(isdigit(exp[i])) {
            int num = 0;

            // handle multi-digit numbers
            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            top = push(top, num);
        }
        else {
            int b = pop(&top);
            int a = pop(&top);
            int res;

            switch(exp[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            top = push(top, res);
            i++;
        }
    }

    return pop(&top);
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("%d", result);

    return 0;
}
