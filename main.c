/*
* tree can only take positive values;
*/
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

    struct Node * root = NULL;

    addNode(&root, 50);
    addNode(&root, 54);
    addNode(&root, 7);
    addNode(&root, 23);
    addNode(&root, 98);
    addNode(&root, 3);

    printInOrder(root);

    findMax(root);
    findMin(root);

    if(contains(root, 100)){
       printf(" contains 100\n");
    }else{
        printf("does not contain 100\n");
    }
    if(contains(root, 98)){
       printf(" contains 98\n");
    }else{
        printf("does not contain 98\n");
    }

    root = deleteNode(root, 23);

    printInOrder(root);
    

    return 0;
}