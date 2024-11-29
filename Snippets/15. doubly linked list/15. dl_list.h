/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../00. includes/node DLL/nodeDLL.h"

/* ******************************************************************************** */

typedef struct dl_list {
    struct nodeDLL *head;
    struct nodeDLL *tail;
} dl_list;

/* ******************************************************************************** */

struct nodeDLL* nodeDLLAlloc();
dl_list dl_list_init();
void dl_list_deinit(dl_list);
struct nodeDLL* dl_list_insert_after(struct nodeDLL*, int);
void dl_list_remove_next(struct nodeDLL*);

/* ******************************************************************************** */