#include <stdio.h>
#include <stdlib.h>

// ---------- Node ----------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ---------- Queue ----------
struct Queue {
    struct Node* arr[200];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 199) return;

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// ---------- Build Tree ----------
struct Node* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {

        struct Node* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// ---------- Zigzag Traversal ----------
void zigzagTraversal(struct Node* root) {

    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {

        int size = q.rear - q.front + 1;
        int level[200];

        for (int i = 0; i < size; i++) {

            struct Node* temp = dequeue(&q);

            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;

            if (temp->left)
                enqueue(&q, temp->left);

            if (temp->right)
                enqueue(&q, temp->right);
        }

        // print level
        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        // change direction
        leftToRight = !leftToRight;
    }
}

// ---------- Main ----------
int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
