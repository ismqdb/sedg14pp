#include <stdio.h>

#include "./12. stack_a.c"
#include "./13. queue_a.c"

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
                x->right = top(stack);
                pop(stack);
            }
            if(!is_empty(stack)){
                x->left = top(stack);
                pop(stack);
            }
        }

        push(stack, x);
    }

    tree_node *returnValue = top(stack);
    pop(stack);
    return returnValue;
}

void visit(tree_node *t){
    printf("%s\n", t->info);
}

void pre_order(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);

    push(stack, t);

    while(is_empty(stack)){
        t = top(stack);
        pop(stack);

        visit(t);

        if(t->right != NULL)
            push(stack, t->right);

        if(t->left != NULL)
            push(stack, t->left);
    }

    stack_deinit(stack);
}

void pre_order_iter(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);

    push(stack, t);

    while(is_empty(stack)){
        t = top(stack);
        pop(stack);

        while(t != NULL){
            visit(t);
            push(stack, t->right);
            t = t->left;
        }
    }
}

void pre_order_recursive(tree_node *t){
    if(t != NULL){
        visit(t);
        pre_order_recursive(t->left);
        pre_order_recursive(t->right);
    }
}

void in_order_recursive(tree_node *t){
    if(t != NULL){
        pre_order_recursive(t->left);
        visit(t);
        pre_order_recursive(t->right);
    }
}

// Pre-order traversal

void remove_recursion_1(tree_node *t){
    l:
        if(t == NULL)
            goto x;
        visit(t);
        remove_recursion_1(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

void remove_recursion_2(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);

    l:
        if(t == NULL)
            goto s;
        visit(t);
        push(stack, t->right);
        t = t->left;
        goto l;

    r:
        t = t->right;
        goto l;

    s:
        if(is_empty(stack))
            goto x;
        t = top(stack);
        pop(stack);
        goto r;

    x: 
        stack_deinit(stack);
}

void remove_recursion_3(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);

    l:
        while(t != NULL){
            visit(t);
            push(stack, t->right);
            t = t->left;
        }

        if(is_empty(stack))
            goto x;

        t = top(stack);
        pop(stack);
        goto l;

    x: 
        stack_deinit(stack);
} 

int main(){
    // A * (((B+C) * (D*E)) + F)
    // A B C + D E * * F + *
    tree_node *root = build_parse_tree();

    pre_order_recursive(root);
    
    putchar(10);
}