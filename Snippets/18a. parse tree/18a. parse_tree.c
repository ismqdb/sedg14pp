#include "./18a. parse_tree.h"

tree_node* build_parse_tree(){
    tree_node *x;
    char c;

    stack_a stack = stack_init(TREE_NODE, 50);

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == '(' || c == ')' || c == ' ')
            continue;

        x = n_init(c);

        if(c == '+' || c == '*'){
            if(!is_empty(stack)){
                x->right = pop_t_node(&stack);
            }
            if(!is_empty(stack)){
                x->left = pop_t_node(&stack);
            }
        }

        push_t_node(&stack, x);
    }

    tree_node *returnValue = pop_t_node(&stack);
    return returnValue;
}