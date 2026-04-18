#include <stdio.h>
#include <stdlib.h>

// ---------- Node Structure ----------
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

// ---------- BST Insert ----------
struct Node* insert(struct Node* root, int data) {

    // empty tree
    if (root == NULL)
        return createNode(data);

    // go left
    if (data < root->data)
        root->left = insert(root->left, data);

    // go right
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// ---------- Inorder Traversal ----------
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ---------- Main ----------
int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}
