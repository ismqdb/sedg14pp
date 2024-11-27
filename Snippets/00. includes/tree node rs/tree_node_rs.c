/* ******************************************************************************** */

#include "./tree_node_rs.h"

/* ******************************************************************************** */

void visit_tree_node_rs(struct tree_node_rs *node){
    printf("%d\n", node->value.integer);
}

/* ******************************************************************************** */

struct tree_node_rs* createNode(int value){
    struct tree_node_rs *t = malloc(sizeof(struct tree_node_rs));
    t->value.integer = value;
    return t;
}

/* ******************************************************************************** */

struct tree_node_rs* insertChild(struct tree_node_rs* node, int value){
    struct tree_node_rs *x = createNode(value);
    node->child = x;
    return x;
}

/* ******************************************************************************** */

struct tree_node_rs* insertSibling(struct tree_node_rs *parent, struct tree_node_rs *node, int value){
    struct tree_node_rs *x = createNode(value);

    struct tree_node_rs *it = node;

    while(it->sibling != NULL){
        it = it->sibling;
    }

    it->sibling = x;
    it->sibling->parent = parent;

    return it->sibling;
}

/* ******************************************************************************** */

void levelOrderTraversal(struct tree_node_rs *node){
    queue_a queue = queue_a_init(INT, 50);
    struct tree_node_rs *temp1, *temp2;

    queue_a_put_tree_node_rs(&queue, node);

    while(!queue_a_is_empty(&queue)){
        node = queue_a_get_tree_node_rs(&queue);

        visit_tree_node_rs(node);

        if(node->sibling){
            temp1 = node;
            while(1){
                temp2 = temp1->sibling;
                temp1->sibling = NULL;
                queue_a_put_tree_node_rs(&queue, temp2);

                if(!temp2->sibling)
                    break;

                temp1 = temp2;
            }
        }

        if(node->child)
            queue_a_put_tree_node_rs(&queue, node->child);
    }

    putchar(10);
}

/* ******************************************************************************** */

void externalPathLengthRS(struct tree_node_rs *t, int level, int *result){
    if(!t) return;

    if(t->child || t->sibling)
        level++;

    if(t->child)
        externalPathLengthRS(t->child, level, result);
    else
        result += level;

    if(t->sibling)
        externalPathLengthRS(t->sibling, level, result);
    else
        result += level;
}

/* ******************************************************************************** */