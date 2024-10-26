#include "./22. recursion_removal.h"

void remove_recursion_1(tree_node *t){
    l:
        if(t == NULL)
            goto x;
        tree_node_visit(t);
        remove_recursion_1(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

void remove_recursion_2(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    l:
        if(t == NULL)
            goto s;
        tree_node_visit(t);
        stack_a_push_tree_node(&stack, t->right);
        t = t->left;
        goto l;

    r:
        t = t->right;
        goto l;

    s:
        if(stack_a_is_empty(&stack))
            goto x;
        t = stack_a_pop_tree_node(&stack);
        goto r;

    x: 
        stack_a_deinit(&stack);
}

void remove_recursion_3(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    l:
        while(t != NULL){
            tree_node_visit(t);
            stack_a_push_tree_node(&stack, t->right);
            t = t->left;
        }

        if(stack_a_is_empty(&stack))
            goto x;

        t = stack_a_pop_tree_node(&stack);
        goto l;

    x: 
        stack_a_deinit(&stack);
}