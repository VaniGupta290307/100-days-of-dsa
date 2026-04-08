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

// find intersection (value-based)
void findIntersection(struct node* head1, struct node* head2) {
    struct node* t1 = head1;

    while(t1 != NULL) {
        struct node* t2 = head2;

        while(t2 != NULL) {
            if(t1->data == t2->data) {
                printf("%d", t1->data);
                return;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node* head1 = createList(n);

    scanf("%d", &m);
    struct node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}
