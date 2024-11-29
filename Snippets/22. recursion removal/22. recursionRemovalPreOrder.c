/* ******************************************************************************** */

#include "./22. recursionRemovalPreOrder.h"

/* ******************************************************************************** */

void preOrderRR0(struct treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        preOrderRR0(t->left);
        preOrderRR0(t->right);
    }
}

/* ******************************************************************************** */

void preOrderRR1(struct treeNode *t){
    l:
        if(t == NULL)
            goto x;
        visitTreeNode(t);
        preOrderRR1(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

/* ******************************************************************************** */

void preOrderRR2(struct treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);

    l:
        if(t == NULL)
            goto s;
        visitTreeNode(t);
        stackArrayPushTreeNode(&stack, t->right);
        t = t->left;
        goto l;

    s:
        if(stackArrayIsEmpty(&stack))
            goto x;
        t = stackArrayPopTreeNode(&stack);
        goto l;

    x: 
        stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

void preOrderRR3(struct treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);

    l:
        while(t != NULL){
            visitTreeNode(t);
            stackArrayPushTreeNode(&stack, t->right);
            t = t->left;
        }

        if(stackArrayIsEmpty(&stack))
            goto x;

        t = stackArrayPopTreeNode(&stack);
        goto l;

    x: 
        stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

void preOrderRR4(struct treeNode *t){
    stackArray stack = stackArrayInit(TREE_NODE, 50);

    stackArrayPushTreeNode(&stack, t);

    while(!stackArrayIsEmpty(&stack)){
        t = stackArrayPopTreeNode(&stack);

        while(t != NULL){
           visitTreeNode(t); 
           stackArrayPushTreeNode(&stack, t->right);
           t = t->left;
        }
    }

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */