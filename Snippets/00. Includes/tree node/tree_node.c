#include "./tree_node.h"

tree_node* n_init(char c){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->info = c;
    return n;
};

void n_deinit(tree_node *n){
    free(n);
}

void visit_n_f(tree_node *t){
    printf("%s\n", t->info);
}