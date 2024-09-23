#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};

struct node *head, *z;

struct node *nalloc(){
    return (struct node*)malloc(sizeof(*head));
}

void ndealloc(struct node *node){
    if(node != NULL)
        free(node);
}

void listinitialize(){
    head = nalloc();
    z = nalloc();

    head->next = z;
    z->next = z;
}

void deletenext(struct node *t){
    struct node *x = t->next;
    t->next = t->next->next;
    ndealloc(x);
}

struct node* insertafter(int v, struct node *t){
    if(t == NULL)
        return NULL;

    struct node *x = nalloc();
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

struct node *movenexttofront(struct node *t){
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

void masssuicide(int n, int m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    int i;
    struct node *head;

    struct node *t = nalloc();
    t->key = 0;
    head = t;

    for(i = 0; i < n; i++){
        t->next = nalloc();
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

int masssuicideArray(int n, int m){
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