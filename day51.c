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

// ---------- BST Insert ----------
struct Node* insert(struct Node* root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// ---------- LCA Function ----------
struct Node* findLCA(struct Node* root, int n1, int n2) {

    while (root != NULL) {

        // both values in left subtree
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // both values in right subtree
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // split point → LCA found
        else
            return root;
    }

    return NULL;
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

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* lca = findLCA(root, a, b);

    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
