/* ******************************************************************************** */

#include "./22. recursion_removal_inorder.h"

/* ******************************************************************************** */

void in_order_rr0(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);
    tree_node *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            stack_a_push_tree_node(&stack, t);
            t = temp;
        } else {
            tree_node_visit(t);
            t = stack_a_pop_tree_node(&stack);
            stack_a_pop_tree_node(&stack);
            
            if(t->right != NULL){
                stack_a_push_tree_node(&stack, t->right);
                t->right = NULL;
            }
        }
    } while(stack_a_is_empty(&stack));

    stack_a_deinit(&stack);
}

/* ******************************************************************************** */