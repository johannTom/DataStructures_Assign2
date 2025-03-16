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

// In-order traversal function
void inorder_traversal(link h) {
    if (h != NULL) {
        // Left subtree
        inorder_traversal(h->pLeft);
        // Print current node
        printf("%s ", h->item.data);
        // Right subtree
        inorder_traversal(h->pRight);
    }
}

// Count nodes in BST
int count(link h) {
    if (h == NULL)
        return 0;
    return count(h->pLeft) + count(h->pRight) + 1;
}

// Calculate tree height
int height(link h) {
    if (h == NULL) return -1;
    int leftH = height(h->pLeft);
    int rightH = height(h->pRight);
    if (leftH > rightH) {
        return(leftH + 1);
    }
    else {
        return(rightH + 1);
    }
}

// Search for an item in the BST
ITEM BSTSearch(link h, char* szSearchKey) {
    ITEM emptyItem = { 0 };  // Default empty Item
    if (h == NULL) return emptyItem;

    int rc = strcmp(szSearchKey, h->item.data);
    if (rc == 0) return h->item;  // Found the item

    if (rc < 0)
        return BSTSearch(h->pLeft, szSearchKey);
    else
        return BSTSearch(h->pRight, szSearchKey);
}
// Search for a key in the BST (using szKey in struct Item)
ITEM Search(char* szKey) {
    return BSTSearch(head, szKey);
}
