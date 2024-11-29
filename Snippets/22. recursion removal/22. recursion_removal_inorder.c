/* ******************************************************************************** */

#include "./22. recursion_removal_inorder.h"

/* ******************************************************************************** */

void in_order_rr0(treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);
    treeNode *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            stackArrayPushTreeNode(&stack, t);
            t = temp;
        } else {
            tree_node_visit(t);
            t = stackArrayPopTreeNode(&stack);
            stackArrayPopTreeNode(&stack);
            
            if(t->right != NULL){
                stackArrayPushTreeNode(&stack, t->right);
                t->right = NULL;
            }
        }
    } while(stackArrayIsEmpty(&stack));

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */