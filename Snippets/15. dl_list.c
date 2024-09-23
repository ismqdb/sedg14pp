

struct dl_list {
    int key;
    struct dl_list *prev;
    struct dl_list *next;
};

struct dl_list* dl_list_alloc(){
    return (struct dl_list*)malloc(sizeof(struct dl_list));
}

struct dl_list *head;
struct dl_list *tail;

void dl_list_init(){
    head = dl_list_alloc();
    tail = dl_list_alloc();

    head->prev = head;
    head->next = tail;

    tail->prev = head;
    tail->next = tail;
}

void dl_list_deinit(){
    free(head);
    free(tail);
}

struct dl_list* dl_list_insert_after(struct dl_list *node, int value){
    struct dl_list *new = dl_list_alloc();
    new->key = value;

    new->next = node->next;
    node->next = new;
    new->prev = node;

    return new;
}

void dl_list_remove_next(struct dl_list *node){
    node->next = node->next->next;
    node->next->prev = node;
}