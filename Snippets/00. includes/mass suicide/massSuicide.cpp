/* ******************************************************************************** */

#include "./massSuicide.hpp"

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

        printf("Dead: %d.\n", idx);
        array[idx] = 0;
        noOfDead++;
    }

    for(int i = 0; i < n; i++)
        if(array[i] == 1){
            free(array);
            return i;
        }

    return 1;
}

/* ******************************************************************************** */

template<typename T>
    void massSuicideLinkedList(int n, int m){
        if(n <= 0 || m <= 0)
            return;

        if(n<m)
            return;

        int i;

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

void massSuicideRecursiveDriver(int n, int m){
    int i;
    struct node<int> *head;

    node<int> *t = new node(0, t);

    for(i = 1; i < n; i++)
        t = new node<int>(i, t->next);
    
    t->next = head;

    massSuicideRecursive(t, 5);    
    putchar(10);
}

/* ******************************************************************************** */

int massSuicideRecursive(node<int> *t, int m){
    if(t != t->next){
        node<int> *head = new node<int>{};

        for(int i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;

        massSuicideRecursive(t, m);
    }
}

/* ******************************************************************************** */