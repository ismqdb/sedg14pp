/* ******************************************************************************** */

#include "./22. recursionRemovalPreOrder.h"

/* ******************************************************************************** */

void traverse_preorder(treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        traverse_preorder(t->left);
        traverse_preorder(t->right);
    }
}

/* ******************************************************************************** */

void remove_recursion_1(treeNode *t){
    l:
        if(t == NULL)
            goto x;
        visitTreeNode(t);
        remove_recursion_1(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

/* ******************************************************************************** */

void remove_recursion_2(treeNode *t){
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

void remove_recursion_3(treeNode *t){
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

void remove_recursion_4(treeNode *t){
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