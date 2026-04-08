#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// create list
struct node* createList(int n) {
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
    return head;
}

// rotate right
struct node* rotateRight(struct node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // find length
    struct node* temp = head;
    int n = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // make circular
    temp->next = head;

    // optimize k
    k = k % n;

    // find new tail (n-k steps)
    int steps = n - k;
    struct node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // new head
    struct node* newHead = newTail->next;

    // break circle
    newTail->next = NULL;

    return newHead;
}

// print list
void printList(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
