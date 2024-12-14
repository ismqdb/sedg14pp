/* ******************************************************************************** */

#include "./massSuicide.h"

/* ******************************************************************************** */

int massSuicideArray(int n, int m){
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

        printf("%d ", idx);
        array[idx] = 0;
        noOfDead++;
    }

    for(int i = 0; i < n; i++)
        if(array[i] == 1){
            free(array);
            putchar(10);
            return i;
        }
}

/* ******************************************************************************** */

void massSuicideLinkedList(int n, int m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    int i;
    struct node *head;

    struct node *t = nodeAlloc();
    t->key = 0;
    head = t;

    for(i = 1; i < n; i++){
        t->next = nodeAlloc();
        t = t->next;
        t->key = i;
    }
    t->next = head;

    while(t != t->next){
        for(i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;
        free(head);
    }

    putchar(10);
}

/* ******************************************************************************** */

void massSuicideRecursiveDriver(int n, int m){
    int i;
    struct node *head;

    struct node *t = nodeAlloc();
    t->key = 0;
    head = t;

    for(i = 1; i < n; i++){
        t->next = nodeAlloc();
        t = t->next;
        t->key = i;
    }
    t->next = head;

    massSuicideRecursive(t, 5);    
    putchar(10);
}

/* ******************************************************************************** */

int massSuicideRecursive(struct node *t, int m){
    if(t != t->next){
        struct node *head;

        for(int i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;
        free(head);

        massSuicideRecursive(t, m);
    }
}

/* ******************************************************************************** */