#pragma once

#define MAX_SIZE 50

typedef struct item {
    char data[MAX_SIZE];
} ITEM;

typedef struct BSTNode {
    ITEM item;
    struct BSTNode* pLeft;
    struct BSTNode* pRight;
} BSTNODE;

typedef struct BSTNode* link;

// Declare head as an extern variable
extern link head;