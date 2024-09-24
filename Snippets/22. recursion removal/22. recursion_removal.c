#include "./22. recursion_removal.h"

void pre_order_iterative(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    stack_a_push_tree_node(&stack, t);

    while(stack_a_is_empty(&stack)){
        t = stack_a_pop_tree_node(&stack);

        while(t != NULL){
            tree_node_visit(t);
            stack_a_push_tree_node(&stack, t->right);
            t = t->left;
        }
    }
}

void pre_order_recursive(tree_node *t){
    if(t != NULL){
        tree_node_visit(t);
        pre_order_recursive(t->left);
        pre_order_recursive(t->right);
    }
}

void in_order_recursive(tree_node *t){
    if(t != NULL){
        pre_order_recursive(t->left);
        tree_node_visit(t);
        pre_order_recursive(t->right);
    }
}

void remove_recursion_1_pre_order(tree_node *t){
    l:
        if(t == NULL)
            goto x;
        tree_node_visit(t);
        remove_recursion_1_pre_order(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

void remove_recursion_2_pre_order(tree_node *t){
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

void remove_recursion_3_pre_order(tree_node *t){
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

int remove_recursion_main(){
    // A * (((B+C) * (D*E)) + F)
    // A B C + D E * * F + *
    tree_node *root = build_parse_tree();

    pre_order_recursive(root);
    
    putchar(10);
}