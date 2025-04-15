#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <stddef.h>

typedef struct BSTNode {
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
} BSTNode;

typedef struct BinarySearchTree {
  BSTNode *root;
  size_t size;
} BinarySearchTree;

BinarySearchTree *bst_create();
void bst_destroy(BinarySearchTree *tree);
int bst_insert(BinarySearchTree *tree, int value);
int bst_delete(BinarySearchTree *tree, int value);
BSTNode *bst_search(BinarySearchTree *, int value);
int bst_contains(BinarySearchTree *tree, int value);
int bst_minimum(BinarySearchTree *tree, int *value);
int bst_maximum(BinarySearchTree *tree, int *value);

#endif // !BINARY_SEARCH_TREE
