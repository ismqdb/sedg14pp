#pragma once

#include <stdlib.h>

typedef struct dll_node {
    int key;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node;

dll_node* dl_list_alloc(){
    return (dll_node*)malloc(sizeof(dll_node));
}