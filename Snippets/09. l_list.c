#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};

struct node *head, *z;

struct node* n_alloc(){
    return (struct node*)malloc(sizeof(*head));
}

void n_dealloc(struct node *node){
    if(node != NULL)
        free(node);
}

void list_initialize(){
    head = n_alloc();
    z = n_alloc();

    head->next = z;
    z->next = z;
}

void delete_next(struct node *t){
    struct node *x = t->next;
    t->next = t->next->next;
    n_dealloc(x);
}

struct node* insert_after(int v, struct node *t){
    if(t == NULL)
        return NULL;

    struct node *x = n_alloc();
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

struct node* move_next_to_front(struct node *t){
    struct node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = head->next;
    head->next = temp;
    return temp;
}

void exchange(struct node *t, struct node *u){
    struct node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

void mass_suicide(int n, int m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    int i;
    struct node *head;

    struct node *t = n_alloc();
    t->key = 0;
    head = t;

    for(i = 0; i < n; i++){
        t->next = n_alloc();
        t = t->next;
        t->key = (i+1);
    }
    t->next = head;

    while(t != t->next){
        for(i = 0; i < m; i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;
        free(head);
    }

    printf("%d\n", t->key);
}

int mass_suicide_Array(int n, int m){
    if(n <= 0 || m <= 0)
        return -1;

    if(n<m)
        return -1;

    int *array = (int*)malloc(n*sizeof(int));

    int noOfDead = 0;
    int currentCount;

    for(int i = 0; i < n; i++)
        array[i] = 1;

    int i = 0;

    while(noOfDead < (n-1)){
        currentCount = 0;
        int idx;

        while(1){
            if(currentCount == m){
                idx = i-1;
                break;
            }
            if(i == n)
                i = 0;
            if(array[i++] == 1)
                currentCount++;
        }

        printf("Dead: %d.\n", idx);
        array[idx] = 0;
        noOfDead++;
    }

    for(int i = 0; i < n; i++)
        if(array[i] == 1){
            free(array);
            return i;
        }
}