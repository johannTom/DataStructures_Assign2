#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"

// Function to generate a random character (lowercase)
char random_char() {
    return 'a' + (rand() % 26);
}

int main() {

    // Number of characters between 11 and 20
    int num_of_chars = rand() % 10 + 11;

    printf("Inserting these random characters into the BST:\n");

    // Insert random characters into the tree
    for (int i = 0; i < num_of_chars; i++) {
        ITEM newItem;
        newItem.data[0] = random_char();
        newItem.data[1] = '\0';
        Insert(newItem);
        printf("%s ", newItem.data);
    }

    printf("\n\nSorted characters in the tree:\n");
    inorder_traversal(head);
    printf("\n");

    // Print the number of nodes in the tree
    printf("\nNumber of nodes in the tree: %d\n", count(head));

    // Print the height of the tree
    printf("Height of the tree: %d\n", height(head));

    char searchKey[2];
    printf("\nEnter a letter to search for in the tree: ");
    scanf(" %c", &searchKey[0]);  // Read a single character

    // Null-terminate the string
    searchKey[1] = '\0';

    // Use the Search function to find the letter
    ITEM foundItem = Search(searchKey);

    // Check if foundItem is an empty/default ITEM (assuming an empty item has all zero values)
    if (foundItem.data[0] != '\0') {  // Assuming 'data' is a string in ITEM struct
        printf("Character '%c' found in the tree.\n", searchKey[0]);
    }
    else {
        printf("Character '%c' not found in the tree.\n", searchKey[0]);
    }
    return 0;
}
