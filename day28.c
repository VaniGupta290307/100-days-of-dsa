#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// create circular linked list
struct node* createCLL(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int val;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // make it circular
    if(temp != NULL) {
        temp->next = head;
    }

    return head;
}

// print circular list
void printCLL(struct node* head) {
    if(head == NULL) return;

    struct node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    int n;

    scanf("%d", &n);

    struct node* head = createCLL(n);

    printCLL(head);

    return 0;
}
