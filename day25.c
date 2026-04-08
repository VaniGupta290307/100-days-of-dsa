#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// create linked list
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

// count occurrences
int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, key;

    scanf("%d", &n);

    struct node* head = createList(n);

    scanf("%d", &key);

    int result = countOccurrences(head, key);

    printf("%d", result);

    return 0;
}
