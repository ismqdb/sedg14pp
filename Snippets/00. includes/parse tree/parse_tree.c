/* ******************************************************************************** */

#include "./parse_tree.h"

/* ******************************************************************************** */

treeNode* build_parse_tree(){
    treeNode *x;
    char c;

    stackArray stack = stackArrayInit(TREE_NODE, 50);

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == '(' || c == ')' || c == ' ')
            continue;

        x = tree_node_init_char(c);

        if(c == '+' || c == '*'){
            if(!stackArrayIsEmpty(&stack)){
                x->right = stackArrayPopTreeNode(&stack);
            }
            if(!stackArrayIsEmpty(&stack)){
                x->left = stackArrayPopTreeNode(&stack);
            }
        }

        stackArrayPushTreeNode(&stack, x);
    }

    treeNode *returnValue = stackArrayPopTreeNode(&stack);
    return returnValue;
}

/* ******************************************************************************** */