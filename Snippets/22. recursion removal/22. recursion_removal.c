#include "./22. recursion_removal.h"

void pre_order_iter(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    stack_a_push_t_node(&stack, t);

    while(stack_a_is_empty(stack)){
        t = stack_a_pop_t_node(&stack);

        while(t != NULL){
            visit_n_f(t);
            stack_a_push_t_node(&stack, t->right);
            t = t->left;
        }
    }
}

void pre_order_recursive(tree_node *t){
    if(t != NULL){
        visit_n_f(t);
        pre_order_recursive(t->left);
        pre_order_recursive(t->right);
    }
}

void in_order_recursive(tree_node *t){
    if(t != NULL){
        pre_order_recursive(t->left);
        visit_n_f(t);
        pre_order_recursive(t->right);
    }
}

// Pre-order traversal

void remove_recursion_1(tree_node *t){
    l:
        if(t == NULL)
            goto x;
        visit_n_f(t);
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
        visit_n_f(t);
        stack_a_push_t_node(&stack, t->right);
        t = t->left;
        goto l;

    r:
        t = t->right;
        goto l;

    s:
        if(stack_a_is_empty(stack))
            goto x;
        t = stack_a_pop_t_node(&stack);
        goto r;

    x: 
        stack_a_deinit(stack);
}

void remove_recursion_3(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    l:
        while(t != NULL){
            visit_n_f(t);
            stack_a_push_t_node(&stack, t->right);
            t = t->left;
        }

        if(stack_a_is_empty(stack))
            goto x;

        t = stack_a_pop_t_node(&stack);
        goto l;

    x: 
        stack_a_deinit(stack);
} 

int remove_recursion_main(){
    // A * (((B+C) * (D*E)) + F)
    // A B C + D E * * F + *
    tree_node *root = build_parse_tree();

    pre_order_recursive(root);
    
    putchar(10);
}