#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n;
    scanf("%d", &n);

    if(n <= 0){
        return 0;
    }

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

    for(int i = 0; i < n; i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;   // first node
            temp = newNode;
        }
        else{
            temp->next = newNode;  // link
            temp = newNode;        // move temp
        }
    }

    // Traversal
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
