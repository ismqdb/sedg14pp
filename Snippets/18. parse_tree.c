#include <stdio.h>

#include "./12. stack_a.c"
#include "./13. queue_a.c"

tree_node* n_init(char c){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->info = c;
    return n;
};

void n_deinit(tree_node *n){
    free(n);
}

typedef struct node_f {
    char info;
    struct node_f *child;
    struct node_f *sibling;
} node_f;

node_f n_f_init(char c){
    node_f n;
    n.info = c;
    return n;
}

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

void visit_n_f(tree_node *t){
    printf("%s\n", t->info);
}

void visit(node_f *t){
    printf("%s\n", t->info);
}
/*
void node_f_level_order(node_f *t){
    queue_a queue = queue_init(TREE_NODE, 50);

    put_tree_node(queue, t);

    while(t != NULL){
        t = get_tree_node(queue);

        put(queue, t->child);

        while(t != NULL){
            visit_n_f(t);
            t = t->sibling;
        }
    }

    queue_deinit(queue);
}*/

void level_order(tree_node *t){
    queue_a queue = queue_init(TREE_NODE, 50);

    put_tree_node(queue, t);

    while(is_queue_empty(queue)){
        t = get_tree_node(queue);
        
        visit_n_f(t);

        if(t->left != NULL)
            put_tree_node(queue, t->left);

        if(t->right != NULL)
            put_tree_node(queue, t->right);
    }

    queue_deinit(queue);
}

void pre_order(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);

    push_t_node(&stack, t);

    while(is_empty(stack)){
        t = pop_t_node(&stack);
        pop_t_node(&stack);

        visit_n_f(t);

        if(t->right != NULL)
            push_t_node(&stack, t->right);

        if(t->left != NULL)
            push_t_node(&stack, t->left);
    }

    stack_deinit(stack);
}

void in_order(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);
    tree_node *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            push_t_node(&stack, t);
            t = temp;
        } else {
            visit_n_f(t);
            t = pop_t_node(&stack);
            pop_t_node(&stack);
            
            if(t->right != NULL){
                push_t_node(&stack, t->right);
                t->right = NULL;
            }
        }
    } while(is_empty(stack));

    stack_deinit(stack);
}

void post_order(tree_node *t){
    stack_a stack = stack_init(TREE_NODE, 50);
    tree_node *temp;

    do {
        if(t->left != NULL && t->right != NULL){
            temp = t->right;
            t->right = NULL;
            push_t_node(&stack, t);
            push_t_node(&stack, temp);
            t = t->left;
        } else {
            visit_n_f(t);
            t = pop_t_node(&stack);
            pop_t_node(&stack);
        }
    } while(is_empty(stack));

    visit_n_f(t);

    stack_deinit(stack);
}