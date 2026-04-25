#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

void addNode(struct Node **root, int data){
    struct Node *newNode = malloc(sizeof(struct Node));

    // Safety check in case memory allocation fails
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return; 
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(*root == NULL){
        printf("Tree is empty, adding first node.\n");
        *root = newNode;
        return; // if this is the first node. create it and then return. skipping the rest of the code.
    }

    struct Node *curr = *root;
    struct Node *parent = NULL;

    // tree traversal
    while(curr != NULL){
        if (data == curr->data) {
        printf("Value %d already exists. Skipping.\n", data);
        free(newNode); // free the memory allocated
        newNode = NULL;
        return; 
        }
        parent = curr;
        if(data < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }

    // attach new node
    if (data < parent->data){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
}

int findMin(struct Node *root){
    if (root == NULL){
        printf("Tree is empty.\n");
        return -1; // using -1 as error code.
    }

    struct Node *curr = root;

    while(curr->left != NULL){
        curr = curr->left;
    }

    return curr->data;
}

int findMax(struct Node *root){
    if (root == NULL){
        printf("Tree is empty.\n");
        return -1; // using -1 as error code.
    }

    struct Node *curr = root;

    while(curr->right != NULL){
        curr = curr->right;
    }

    return curr->data;
}

bool contains(struct Node *root, int data){
    if (root == NULL){
        printf("Tree is empty.\n");
        return false; 
    }

    struct Node *curr = root;

    while(curr != NULL){
        if(data == curr->data){
            return true;
        }
        if( data > curr->data){
            curr = curr->right;
        }else{
            curr = curr->left;
        }
    }
    return false;
}

struct Node* deleteNode(struct Node* root, int data){
    struct Node * curr = root;
    struct Node * parent = NULL;

    // search tree for node and keep track of its parent
    while (curr != NULL && curr->data != data){
        parent = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr == NULL){
        return root;
    }
    // for if the node has 2 children
    if (curr->left != NULL && curr->right != NULL){
        struct Node *successorParent = curr;
        struct Node *successor = curr->right;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Copy successor's data into the node thas is being deleted
        curr->data = successor->data;


        // change target to delet tehe successor instead
        // successor is guaranteed to ahve at most 1 child
        curr = successor;
        parent = successorParent;
    }

    struct Node *child;
    if (curr->left != NULL) {
        child = curr->left;
    } else {
        child = curr->right;
    }

    // Reconnect the tree
    if (parent == NULL) {
        // deleting the root node itself
        root = child;
    } else if (parent->left == curr) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    //free the memory
    free(curr);
    curr = NULL;
    
    return root;

}

void printInOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree (smaller numbers)
    printInOrder(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Traverse the right subtree (larger numbers)
    printInOrder(root->right);
}