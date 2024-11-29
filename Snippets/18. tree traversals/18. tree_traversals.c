/* ******************************************************************************** */

#include "./18. tree_traversals.h"

/* ******************************************************************************** */

void level_order(treeNode *t){
    queueArray queue = queueArrayInit(TREE_NODE, 50);

    queueArrayPutTreeNode(&queue, t);

    while(!queueArrayIsEmpty(&queue)){
        t = queueArrayGetTreeNode(&queue);
        
        visitTreeNode(t);

        if(t->left != NULL)
            queueArrayPutTreeNode(&queue, t->left);

        if(t->right != NULL)
            queueArrayPutTreeNode(&queue, t->right);
    }

    queueArrayDeinit(&queue);
}

/* ******************************************************************************** */

void pre_order(treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);

    stackArrayPushTreeNode(&stack, t);

    while(!stackArrayIsEmpty(&stack)){
        t = stackArrayPopTreeNode(&stack);

        visitTreeNode(t);

        if(t->right != NULL)
            stackArrayPushTreeNode(&stack, t->right);

        if(t->left != NULL)
            stackArrayPushTreeNode(&stack, t->left);
    }

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

void in_order(treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);
    treeNode *temp;
    
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

void post_order(treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);
    treeNode *temp;

    do {
        if(t->left != NULL && t->right != NULL){
            temp = t->right;
            t->right = NULL;
            stackArrayPushTreeNode(&stack, t);
            stackArrayPushTreeNode(&stack, temp);
            t = t->left;
        } else {
            visitTreeNode(t);
            t = stackArrayPopTreeNode(&stack);
            stackArrayPopTreeNode(&stack);
        }
    } while(!stackArrayIsEmpty(&stack));

    visitTreeNode(t);

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

void pre_order_iterative(treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);

    stackArrayPushTreeNode(&stack, t);

    while(stackArrayIsEmpty(&stack)){
        t = stackArrayPopTreeNode(&stack);

        while(t != NULL){
            visitTreeNode(t);
            stackArrayPushTreeNode(&stack, t->right);
            t = t->left;
        }
    }
}

/* ******************************************************************************** */

void pre_order_recursive(treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        pre_order_recursive(t->left);
        pre_order_recursive(t->right);
    }
}

/* ******************************************************************************** */

void in_order_recursive(treeNode *t){
    if(t != NULL){
        pre_order_recursive(t->left);
        visitTreeNode(t);
        pre_order_recursive(t->right);
    }
}

/* ******************************************************************************** */