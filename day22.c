#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n;
    scanf("%d", &n);

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

    // Creating Linked List
    for(int i = 0; i < n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Counting Nodes
    int count = 0;
    temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
