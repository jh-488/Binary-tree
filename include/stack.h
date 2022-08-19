#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define bool int

// A structure to represent a stack nodes as a linked list
struct sNode
{
  struct Node* t;
  struct sNode* next;
};

void push(struct sNode**,struct Node*);
bool isEmpty(struct sNode*);
struct Node* pop(struct sNode**);