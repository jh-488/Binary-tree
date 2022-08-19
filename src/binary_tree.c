#include <stdio.h>
#include <stdlib.h>
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#include "../include/binary_tree.h"


// Creation of a node
struct Node* CreateNode(int _data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    else
    {
        node->data = _data;

        node->left = NULL;
        node->right = NULL;
    }
    return node;    
}

// Deallocate memory
void Deallocate(struct Node* node)
{
    // do nothing if passed a non-existent node
    if (node == NULL)
    {
        return;
    }
    else
    {
    // recursion
        Deallocate(node->left);
        Deallocate(node->right);
        free(node);
    }
} 

// Insert left node
struct Node* InsertLeft(struct Node* parent, int data)
{
    if(parent == NULL)
    {
        printf("Tree is empty\n");
        return parent;
    }
    else
    {
        struct Node* left_child = CreateNode(data);
        parent->left = left_child;
        return left_child;
    }
}

// Insert right node
struct Node* InsertRight(struct Node* parent, int data)
{
    if(parent == NULL)
    {
        printf("Tree is empty\n");
        return parent;
    }
    else
    {
    struct Node* right_child = CreateNode(data);
    parent->right = right_child;
    return right_child;
    }
}   

// Traversals
void PrintPreOrder(struct Node* node) // nlr
{
    if(node == NULL)
    {
        return ; 
    }
    else
    {
        printf("%d ", node->data);
        PrintPreOrder(node->left);
        PrintPreOrder(node->right);
    }
    
}

void PrintInOrder(struct Node* node) // lnr
{
    if(node == NULL)
    {
        return ;
    }
    else
    {
        PrintInOrder(node->left);
        printf("%d ", node->data);
        PrintInOrder(node->right);
    }
}

void PrintPostOrder(struct Node* node) // lrn
{
    if(node == NULL)
    {
        return ;
    }
    else
    {
        PrintPostOrder(node->left);
        PrintPostOrder(node->right);
        printf("%d ", node->data);
    }
}

// Searching for a node in a binary search tree
struct Node* Search(struct Node* root, int _data)
{
    if(root == NULL)
    {
        printf("Tree is empty or data doesn't exist\n");
        return root;
    }
    if(_data == root->data)
    {
        printf("Data found : %d\n", _data);
        return root;
    }
    else if(_data < root->data)
    {
        Search(root->left, _data);
    }
    else if(_data > root->data)
    {
        Search(root->right, _data);
    }
}

// Get Inorder successor of a node
struct Node* minKey(struct Node* root)
{
    struct Node* temp = root;
    // find the last left leaf
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// Deletion of a node
struct Node* DeleteNode(struct Node* root, int _data)
{
    // check if node is empty
    if(root == NULL)
    {
        printf("Tree is empty or data doesn't exist\n");
        return root;
    }
    // check if the key smaller or bigger than the root
    if(_data < root->data)
    {
        // check the left subtree
        root->left = DeleteNode(root->left, _data);
    }
    else if(_data > root->data)
    {
        //check the right subtree
        root->right = DeleteNode(root->right, _data);
    }
    else
    {
    // if node have one child or no child
        if(root->left == NULL) 
        {
            struct Node* temp = root->right;
            printf("Node is deleted successfully.\n");
            free(root);
            return temp;
        }
        else if(root->right == NULL) 
        {
            struct Node* temp = root->left;
            printf("Node is deleted successfully.\n");
            free(root);
            return temp;
        }
    // if node have two children
        struct Node* temp = minKey(root->right); // find the inorder successor
        root->data = temp->data; // exchange the keys 
        root->right = DeleteNode(root->right, temp->data); // delete the inorder successor
    }
    return root;
}

// Invert binary tree
// iterative
void InvertIterative(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        struct sNode* stack = NULL; // initialize stack
        push(&stack, root);

        while(!isEmpty(stack))
        {
            struct Node* temp = pop(&stack);

            // Swap
            struct Node* tempNode = temp->left;
            temp->left = temp->right;
            temp->right = tempNode;

            if(temp->left != NULL)
            {
                push(&stack, temp->left);
            }
            if(temp->right != NULL)
            {
                push(&stack, temp->right);
            }
        }
    }
}

// Recursive
struct Node* InvertRecursive(struct Node* root)
{
    // check if tree is empty
    if(root == NULL)
    {
        return root;
    }
    else
    {
        // swap the left and right subtree
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        // invert the left and right subtree
        InvertRecursive(root->left);
        InvertRecursive(root->right);

        return root;
    }
}

// Get height of a tree
int height(struct Node* root)
{
    // base case: empty tree has a height of 0
    if (root == NULL) {
        return -1;
    }  
    // recur for the left and right subtree and consider maximum depth
    return 1 + MAX(height(root->left), height(root->right));
}

// Get the complexity of a binary search tree
bool BST_Complexity(struct Node* root)
{
    int left_height, right_height;
    // Check if the tree is empty
    if (root == NULL)
    {
        printf("Time complexity O(log n).\n");
        return 1;
    }
    else
    {   // Get the height of the left and right subtrees
        left_height = height(root->left);
        right_height = height(root->right);
        // Calculate the absolute difference between the two heights
        if(abs(left_height - right_height > 1))
        {
            printf("Time complexity O(n).\n");
            return 0;
        }
        else
        {
            printf("Time complexity O(log n).\n");
            return 1;
        }
    }
}