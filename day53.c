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

// ---------- Queue storing node + HD ----------
struct Pair {
    struct Node* node;
    int hd;
};

struct Queue {
    struct Pair arr[200];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    if (q->rear == 199) return;

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct Pair dequeue(struct Queue* q) {
    struct Pair temp = q->arr[q->front];

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
    enqueue(&q, root, 0);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Pair p = dequeue(&q);
        struct Node* curr = p.node;

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// ---------- Vertical Order ----------
void verticalOrder(struct Node* root) {

    if (!root) return;

    int result[200][200] = {0};
    int count[200] = {0};

    int offset = 100; // handle negative HD

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {

        struct Pair p = dequeue(&q);
        struct Node* node = p.node;
        int hd = p.hd;

        result[hd + offset][count[hd + offset]++] = node->data;

        if (node->left)
            enqueue(&q, node->left, hd - 1);

        if (node->right)
            enqueue(&q, node->right, hd + 1);
    }

    // print from leftmost column
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}
