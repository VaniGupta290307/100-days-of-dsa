#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* next;
};

// create polynomial
struct node* createPoly(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int c, e;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->coef = c;
        newNode->exp = e;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// print polynomial
void printPoly(struct node* head) {
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    struct node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
