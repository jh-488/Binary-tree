#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define bool int


// Representation of a node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(int _data);
void Deallocate(struct Node* node);
struct Node* InsertLeft(struct Node* parent, int data);
struct Node* InsertRight(struct Node* parent, int data);
void PrintPreOrder(struct Node* node);
void PrintInOrder(struct Node* node);
void PrintPostOrder(struct Node* node);
struct Node* Search(struct Node* root, int _data);
struct Node* minKey(struct Node* root);
struct Node* DeleteNode(struct Node* root, int _data);
void InvertIterative(struct Node* root);
struct Node* InvertRecursive(struct Node* root);
int height(struct Node* root);
bool BST_Complexity(struct Node* root);