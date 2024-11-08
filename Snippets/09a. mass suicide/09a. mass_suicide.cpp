#include "./09a. mass_suicide.hpp"

void mass_suicide(int n, int m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    int i;
    node *head;

    node *t = node_alloc();
    t->key = 0;
    head = t;

    for(i = 0; i < n; i++){
        t->next = node_alloc();
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

int mass_suicide_array(int n, int m){
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