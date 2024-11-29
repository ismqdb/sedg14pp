/* ******************************************************************************** */

#include "./22. recursionRemovalInOrder.h"

/* ******************************************************************************** */

void inOrderRR0(struct treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);
    struct treeNode *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            stackArrayPushTreeNode(&stack, t);
            t = temp;
        } else {
            visitTreeNode(t);
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