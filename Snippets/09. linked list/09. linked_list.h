#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../00. includes/node/node.h"

typedef struct linked_list {
    node *head;
    node *z;
} linked_list;

linked_list list_initialize();
void delete_next(node*);
node* insert_after(int, node*);
node* move_next_to_front(linked_list, node*);
void exchange(node*, node*);