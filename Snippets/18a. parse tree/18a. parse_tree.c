#include "./18a. parse_tree.h"

tree_node* build_parse_tree(){
    tree_node *x;
    char c;

    stack_a stack = stack_a_init(TREE_NODE, 50);

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == '(' || c == ')' || c == ' ')
            continue;

        x = tree_node_init(c);

        if(c == '+' || c == '*'){
            if(!stack_a_is_empty(&stack)){
                x->right = stack_a_pop_tree_node(&stack);
            }
            if(!stack_a_is_empty(&stack)){
                x->left = stack_a_pop_tree_node(&stack);
            }
        }

        stack_a_push_tree_node(&stack, x);
    }

    tree_node *returnValue = stack_a_pop_tree_node(&stack);
    return returnValue;
}