#include "../18a. parse tree/18a. parse_tree.h"

void level_order(tree_node *t){
    queue_a queue = queue_a__init(TREE_NODE, 50);

    queue_a_put_tree_node(&queue, t);

    while(queue_a_is_empty(&queue)){
        t = queue_a_get_tree_node(&queue);
        
        tree_node_visit(t);

        if(t->left != NULL)
            queue_a_put_tree_node(&queue, t->left);

        if(t->right != NULL)
            queue_a_put_tree_node(&queue, t->right);
    }

    queue_a_deinit(&queue);
}

void pre_order(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);

    stack_a_push_t_node(&stack, t);

    while(stack_a_is_empty(&stack)){
        t = stack_a_pop_t_node(&stack);
        stack_a_pop_t_node(&stack);

        tree_node_visit(t);

        if(t->right != NULL)
            stack_a_push_t_node(&stack, t->right);

        if(t->left != NULL)
            stack_a_push_t_node(&stack, t->left);
    }

    stack_a_deinit(&stack);
}

void in_order(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);
    tree_node *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            stack_a_push_t_node(&stack, t);
            t = temp;
        } else {
            tree_node_visit(t);
            t = stack_a_pop_t_node(&stack);
            stack_a_pop_t_node(&stack);
            
            if(t->right != NULL){
                stack_a_push_t_node(&stack, t->right);
                t->right = NULL;
            }
        }
    } while(stack_a_is_empty(&stack));

    stack_a_deinit(&stack);
}

void post_order(tree_node *t){
    stack_a stack = stack_a_init(TREE_NODE, 50);
    tree_node *temp;

    do {
        if(t->left != NULL && t->right != NULL){
            temp = t->right;
            t->right = NULL;
            stack_a_push_t_node(&stack, t);
            stack_a_push_t_node(&stack, temp);
            t = t->left;
        } else {
            tree_node_visit(t);
            t = stack_a_pop_t_node(&stack);
            stack_a_pop_t_node(&stack);
        }
    } while(stack_a_is_empty(&stack));

    tree_node_visit(t);

    stack_a_deinit(&stack);
}