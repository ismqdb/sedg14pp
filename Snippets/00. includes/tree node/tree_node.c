/* ******************************************************************************** */

#include "./tree_node.h"

/* ******************************************************************************** */

tree_node* tree_node_init(){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    return n;
};

tree_node* tree_node_init_char(char c){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->info = c;
    return n;
};

void tree_node_deinit(tree_node *n){
    free(n);
}

void tree_node_visit(tree_node *t){
    if(t == NULL)
        return;
    
    printf("%c ", t->info);
}

/* ******************************************************************************** */

int tnode_compare(const void *t1, const void *t2){
    struct tnode_pair *d1 = (struct tnode_pair*)t1;
    struct tnode_pair *d2 = (struct tnode_pair*)t2;

    return d1->index < d2->index;
}

/* ******************************************************************************** */

void drawBinaryTreeRecursive(struct tree_node* t, struct tnode_pair **pairs, int left, int right){
        if(t == NULL)
            return;
        else {
            struct tnode_pair *x = (struct tnode_pair*)malloc(sizeof(struct tnode_pair));
            x->node = t;
            x->index = (left+right)/2;
            pairs[sizeof(pairs)/sizeof(struct tnode_pair)] = x;
        }

        if(t->left != NULL){
            int middle = (left+right)/2;
            drawBinaryTreeRecursive(t->left, pairs, left, middle);
        }

        if(t->right != NULL){
            int middle = (left+right)/2;
            drawBinaryTreeRecursive(t->right, pairs, middle, right);
        }
}

/* ******************************************************************************** */

void externalPathLength(tree_node *t, int level, int *len){
    if(t->left || t->right)
        level++;

    if(t->left)
        externalPathLength(t->left, level, len);
    else
        len += level;

    if(t->right)
        externalPathLength(t->right, level, len);
    else
        len += level;
}

/* ******************************************************************************** */

int drawBinaryTreeRecursiveDriver(){
    int screenWidth = 80;

    tree_node *t = build_parse_tree();
    struct tnode_pair **pairs = (struct tnode_pair**)malloc(sizeof(struct tnode_pair**));

    drawBinaryTreeRecursive(t, pairs, 0, screenWidth);

    qsort(pairs, sizeof(pairs)/sizeof(struct tnode_pair), sizeof(struct tnode_pair), tnode_compare);

    putchar(10);
    for(int pos = 0, printed = 0; pos < screenWidth; pos++){
        if(pairs[printed]->index == pos)
            printf("%c", pairs[printed++]->node->info);
        else
            putchar(' ');
    }

    putchar(10);
    putchar(10);

    return 1;
}

/* ******************************************************************************** */