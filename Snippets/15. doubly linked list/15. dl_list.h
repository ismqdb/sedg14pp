#pragma once

#include "../00. includes/dll node/dll_node.h"

typedef struct dl_list {
    dll_node *head;
    dll_node *tail;
} dl_list;

dll_node* dl_list_alloc();
dl_list dl_list_init();
void dl_list_deinit(dl_list);
dll_node* dl_list_insert_after(dll_node*, int);
void dl_list_remove_next(dll_node*);