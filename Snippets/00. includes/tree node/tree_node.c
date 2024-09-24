#include "./tree_node.h"

tree_node* tree_node_init(char c){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->info = c;
    return n;
};

void tree_node_deinit(tree_node *n){
    free(n);
}

void tree_node_visit(tree_node *t){
    printf("%s\n", t->info);
}