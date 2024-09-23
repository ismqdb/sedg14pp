

struct dllist {
    int key;
    struct dllist *prev;
    struct dllist *next;
};

struct dllist *dllalloc(){
    return (struct dllist*)malloc(sizeof(struct dllist));
}

struct dllist *head;
struct dllist *tail;

void dllistinit(){
    head = dllalloc();
    tail = dllalloc();

    head->prev = head;
    head->next = tail;

    tail->prev = head;
    tail->next = tail;
}

void dllistdeinit(){
    free(head);
    free(tail);
}

struct dllist* dlListInsertAfter(struct dllist *node, int value){
    struct dllist *new = dllalloc();
    new->key = value;

    new->next = node->next;
    node->next = new;
    new->prev = node;

    return new;
}

void dlListRemoveNext(struct dllist *node){
    node->next = node->next->next;
    node->next->prev = node;
}