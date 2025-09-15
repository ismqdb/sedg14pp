/* ******************************************************************************** */

#include "./massSuicide.hpp"

/* ******************************************************************************** */

i32 massSuicideArray(i32 n, i32 m){
    if(n <= 0 || m <= 0)
        return -1;

    if(n<m)
        return -1;

    i32 *array = (i32*)malloc(n*sizeof(i32));

    i32 noOfDead = 0;
    i32 currentCount;

    for(i32 i = 0; i < n; i++)
        array[i] = 1;

    i32 i = 0;

    while(noOfDead < (n-1)){
        currentCount = 0;
        i32 idx;

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

    for(i32 i = 0; i < n; i++)
        if(array[i] == 1){
            free(array);
            return i;
        }

    return 1;
}

/* ******************************************************************************** */

template<typename T>
    none massSuicideLinkedList(i32 n, i32 m){
        if(n <= 0 || m <= 0)
            return;

        if(n<m)
            return;

        i32 i;

        node<char> *t = new node<char>{};
        node<char> *head = new node<char>{};

        t->key = 0;
        head = t;

        for(i = 0; i < n; i++){
            t->next = new node<char>{};
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

/* ******************************************************************************** */

none massSuicideRecursiveDriver(i32 n, i32 m){
    i32 i;
    struct node<i32> *head;

    node<i32> *t = new node(0, t);

    for(i = 1; i < n; i++)
        t = new node<i32>(i, t->next);
    
    t->next = head;

    massSuicideRecursive(t, 5);    
    putchar(10);
}

/* ******************************************************************************** */

i32 massSuicideRecursive(node<i32> *t, i32 m){
    if(t != t->next){
        node<i32> *head = new node<i32>{};

        for(i32 i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;

        massSuicideRecursive(t, m);
    }

    return 1;
}

/* ******************************************************************************** */