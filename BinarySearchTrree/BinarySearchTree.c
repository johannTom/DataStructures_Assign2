#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


link head = NULL;

// Function to create a new BST node
link NEW(ITEM item, link left, link right) {
    link pNew = (link)malloc(sizeof(*pNew));
    if (pNew == NULL) {
        //Memory allocation error
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    pNew->item = item;
    pNew->pLeft = left;
    pNew->pRight = right;
    return pNew;
}

// Recursive function to insert into BST
link InsertBST(link h, ITEM item) {
    if (h == NULL) {
        // Create new node if tree/subtree is empty
        return NEW(item, NULL, NULL);
    }

    int rc = strcmp(item.data, h->item.data);

    if (rc < 0) {
        // Insert in left subtree
        h->pLeft = InsertBST(h->pLeft, item);
    }
    else if (rc > 0) {
        // Insert in right subtree
        h->pRight = InsertBST(h->pRight, item);
    }

    return h; // Return updated subtree
}

// Insert function to update global head
void Insert(ITEM item) {
    head = InsertBST(head, item);
}