#include <stdio.h>
#include <stdlib.h>
#include "../include/binary_tree.h"


int main()
{
    // Create the root 
    struct Node* tree = CreateNode(5);

    // Insert the different childs
    InsertLeft(tree, 1);
    InsertRight(tree, 7);
    InsertLeft(tree->left, 0);
    InsertRight(tree->left, 4);
    InsertLeft(tree->right, 6);

    /* The above called functions will create this binary search tree

          5
       /     \
      1       7
     /  \    /  
    0    4   6 
      
    */

    // Print the different tree traversals
    printf("Preorder : ");
    PrintPreOrder(tree);
    printf("\n");
    printf("Inorder : ");
    PrintInOrder(tree);
    printf("\n");
    printf("Postorder : ");
    PrintPostOrder(tree);
    printf("\n");
    
    // Search Node
    Search(tree, 4);

    // Delete node and print new tree
    DeleteNode(tree, 1);
    
    // Inverting the new tree (after deletion)
    InvertIterative(tree);
    //InvertRecursive(tree);

    // Print the inorder traversal after inversion
    PrintInOrder(tree);
    printf("\n");

    // Get the complexity of the binary search tree
    BST_Complexity(tree);

    Deallocate(tree);

    return 0;
}