#ifndef BST_H
#define BST_H

#include <stdbool.h> // Required for the bool return type in contains()

// Structure definition for a Binary Search Tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// --------------------------------------------------------
// Function Prototypes
// --------------------------------------------------------

// Adds a new node with the given data to the BST
void addNode(struct Node **root, int data);

// Finds and returns the minimum value in the BST
int findMin(struct Node *root);

// Finds and returns the maximum value in the BST
int findMax(struct Node *root);

// Checks if a specific value exists in the BST
bool contains(struct Node *root, int data);

// Deletes a node with the specified data and returns the updated root
struct Node* deleteNode(struct Node *root, int data);

// Prints the tree's values in ascending numerical order
void printInOrder(struct Node *root);

#endif // BST_H