/* ******************************************************************************** */

#include "./18. treeTraversal.h"

/* ******************************************************************************** */

void levelOrder(struct treeNode *t){
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

void preOrder(struct treeNode *t){
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

void inOrder(struct treeNode *t){
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

void postOrder(struct treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);
    struct treeNode *temp;

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

void preOrderIterative(struct treeNode *t){
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

void preOrderRecursive(struct treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        preOrderRecursive(t->left);
        preOrderRecursive(t->right);
    }
}

/* ******************************************************************************** */

void inOrderRecursive(struct treeNode *t){
    if(t != NULL){
        preOrderRecursive(t->left);
        visitTreeNode(t);
        preOrderRecursive(t->right);
    }
}

/* ******************************************************************************** */