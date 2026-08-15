#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insertion
struct Node* insert(struct Node* root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

// Deletion
struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL)
        return root;

    // Search in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // Search in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Node found
    else {

        // Case 1: No left child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("BST before deletion: ");
    inorder(root);

    root = deleteNode(root, 50);

    printf("\nBST after deletion: ");
    inorder(root);

    return 0;
}
