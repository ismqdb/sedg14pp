#include "./parse_tree.h"

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

        x = tree_node_init_char(c);

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

    /* Distance between two symbols on the same row. */
    int distance = screen_width;

    /* Offset to the first letter from terminal start */
    int offset = (screen_width/2)-1;

    int first_letter_in_row = 1;

    int nodes_per_level[100] = {0};
    nodes_per_level[1] = 1;

    queue_a queue = queue_a_init(TREE_NODE, 50);

    queue_a_put_tree_node(&queue, t);

    for(int i = 0; i < offset; i++)
        putchar(0x20);

    while(!queue_a_is_empty(&queue)){
        if(is_new_level(nodes_per_level, nodes_visited)){
            current_level++;
            distance /= 2;
            offset = ((offset+1)/2)-1;
            putchar(10);
            for(int i = 0; i < offset; i++)
                putchar(0x20);
            first_letter_in_row = 1;
        }
        
        nodes_visited++;

        t = queue_a_get_tree_node(&queue);

        if(!first_letter_in_row)
            for(int i = 0; i < distance-1; i++)
                putchar(0x20);

        if(first_letter_in_row)
            first_letter_in_row = 0;

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