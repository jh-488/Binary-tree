#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define bool int
#include "../include/stack.h"

// Source https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

/* Function to push an item to sNode*/
void push(struct sNode** top_ref, struct Node* t)
{
  /* allocate tNode */
  struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }           
 
  /* put in the data  */
  new_tNode->t  = t;
 
  /* link the old list off the new tNode */
  new_tNode->next = (*top_ref);  
 
  /* move the head to point to the new tNode */
  (*top_ref)    = new_tNode;
}
 
/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct sNode* top)
{
   return (top == NULL)? 1 : 0;
} 

/* Function to pop an item from stack*/
struct Node* pop(struct sNode** top_ref)
{
  struct Node* res;
  struct sNode* top;
 
  /*If sNode is empty then error */
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->t;
     *top_ref = top->next;
     free(top);
     return res;
  }
}