#include <stdio.h>

#include "./12. stack_a.c"
#include "./13. queue_a.c"

typedef struct node {
    char info;
    node *left;
    node *right;
} node;

node* n_init(char c){
    node *n = (node*)malloc(sizeof(node));
    n->info = c;
    return n;
};

void n_deinit(node *n){
    free(n);
}

typedef struct nodeF {
    char info;
    node_f *child;
    node_f *sibling;
} node_f;

node_f n_f_init(char c){
    node_f n;
    n.info = c;
    return n;
}

node* build_parse_tree(){
    node *x;
    char c;

    stack_a stack = stack_init(50);

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

    node *returnValue = top(stack);
    pop(stack);
    return returnValue;
}

void visit(node *t){
    printf("%s\n", t->info);
}

void visit(node_f *t){
    printf("%s\n", t->info);
}

void node_f_level_order(node_f *t){
    queue_a queue = queue_init(50);

    put(queue, t);

    while(t != NULL){
        t = get(queue);

        put(queue, t->child);

        while(t != NULL){
            visit(t);
            t = t->sibling;
        }
    }

    queue_deinit(queue);
}

void level_order(node *t){
    queue_a queue = queue_init(50);

    put(queue, t);

    while(is_queue_empty(queue)){
        t = get(queue);
        
        visit(t);

        if(t->left != NULL)
            put(queue, t->left);

        if(t->right != NULL)
            put(queue, t->right);
    }

    queue_deinit(queue);
}

void pre_order(node *t){
    stack_a stack = stack_init(50);

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

void in_order(node *t){
    stack_a stack = stack_init(50);
    node *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            push(stack, t);
            t = temp;
        } else {
            visit(t);
            t = top(stack);
            pop(stack);
            
            if(t->right != NULL){
                push(stack, t->right);
                t->right = NULL;
            }
        }
    } while(is_empty(stack));

    stack_deinit(stack);
}

void post_order(node *t){
    stack_a stack = stack_init(50);
    node *temp;

    do {
        if(t->left != NULL && t->right != NULL){
            temp = t->right;
            t->right = NULL;
            push(stack, t);
            push(stack, temp);
            t = t->left;
        } else {
            visit(t);
            t = top(stack);
            pop(stack);
        }
    } while(is_empty(stack));

    visit(t);

    stack_deinit(stack);
}

int main(){
    // A * (((B+C) * (D*E)) + F)
    // A B C + D E * * F + *

}