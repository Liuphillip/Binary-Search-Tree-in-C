# Binary Search Tree (BST) in C

A lightweight, efficient implementation of a Binary Search Tree data structure written in C. This project covers the fundamental operations required to manage a sorted hierarchical data structure.

## Features
* **Insertion:** Add nodes while maintaining the BST property (Left < Root < Right).
* **Search:** Efficient O(log n) lookup for specific values.
* **Deletion:** Handles all three cases (leaf nodes, one child, and two children).
* **Traversals:** Includes In-order, Pre-order, and Post-order tree walking.
* **Memory Management:** Functions to clear the tree and prevent memory leaks.

## How to Build and Run

To compile the project using `gcc`, run the following command in your terminal:

```bash
gcc main.c bst.c -o bst_demo
