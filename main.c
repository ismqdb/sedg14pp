#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Snippets/00. includes/parse tree/parse_tree.h"
#include "Snippets/18. tree traversals/18. tree_traversals.h"
#include "Snippets/22. recursion removal/22. recursion_removal.h"

int is_new_level(int *nodes_per_level, int nodes_visited){
    int count = 0;

    for(int i = 1; nodes_per_level[i] != 0; i++){
        count += nodes_per_level[i];

        if(count == nodes_visited)
            return 1;
    }

    return 0;
}

void draw_binary_tree(tree_node *t){
    putchar(10);

    const int screen_width = 80;

    int nodes_visited = 0;
    int current_level = 1;
    int no_of_blank_space = screen_width/2;

    int nodes_per_level[100] = {0};
    nodes_per_level[1] = 1;

    queue_a queue = queue_a_init(TREE_NODE, 50);

    queue_a_put_tree_node(&queue, t);

    while(!queue_a_is_empty(&queue)){
        if(is_new_level(nodes_per_level, nodes_visited)){
            current_level++;
            no_of_blank_space = screen_width / nodes_per_level[current_level];
            putchar(10);
        }
        
        nodes_visited++;

        t = queue_a_get_tree_node(&queue);

        for(int i = 0; i < no_of_blank_space-1; i++)
            putchar(0x20);

        if(t != NULL)
            putchar(t->info);
        else
            putchar('.');

        if(t != NULL){
            queue_a_put_tree_node(&queue, t->left);
            queue_a_put_tree_node(&queue, t->right);
            nodes_per_level[current_level+1] += 2;
        }
    }

    queue_a_deinit(&queue);

    putchar(10);
}

int main(){
    tree_node *t = build_parse_tree();
    draw_binary_tree(t);
}

// A B C + D E * * F + *