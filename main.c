/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "Snippets/12. stack/12. stackArray.h"

/* ******************************************************************************** */

void* addInt(void *arg){
    struct stackArray *stack = (struct stackArray*)arg;
    for(int i = 0; i < 20; i++)
        stackArrayPushInt(stack, i);

    pthread_exit(NULL);
}

/* ******************************************************************************** */

void* removeInt(void *arg){
    struct stackArray *stack = (struct stackArray*)arg;

    while(!stackArrayIsEmpty(stack))
        printf("%d\n", stackArrayPopInt(stack));

    return NULL;
}

/* ******************************************************************************** */

int main(){
    struct stackArray stack = stackArrayInit(INT, 50);

    pthread_t addThread;
    pthread_t removeThread;

    int s1 = pthread_create(&addThread,     NULL, addInt,       (void*)&stack);
    int s2 = pthread_create(&removeThread,  NULL, removeInt,    (void*)&stack);

    pthread_join(addThread,     NULL);
    pthread_join(removeThread,  NULL);
}

/* ******************************************************************************** */