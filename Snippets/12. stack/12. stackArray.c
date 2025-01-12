/* ******************************************************************************** */

#include "./12. stackArray.h"

/* ******************************************************************************** */

struct stackArray stackArrayInit(treeNodeDataType type, int size){
    struct stackArray stack;
    stack.currentSize = 0;
    stack.chunkSize = 25;
    stack.type = type;

    switch(type){
        case INT:
            stack.data.integer = heapAllocSized(int, size);
            break;
        case TREE_NODE:
            stack.data.treeNode = heapAllocArray(struct treeNode, size);
            break;
    }

    stack.p = 0;
    stack.currentSize += size;

    pthread_mutex_init(&stack.dataMutex, NULL);
    pthread_mutex_init(&stack.ptrMutex, NULL);
    pthread_cond_init(&stack.hasDataCondVar, NULL);

    return stack;
}

/* ******************************************************************************** */

void stackArrayDeinit(struct stackArray *stack){
    stack->p = 0;

    switch(stack->type){
        case INT:
            free(stack->data.integer);
            break;
        case TREE_NODE:
            free(stack->data.treeNode);
            break;
    }

    pthread_mutex_destroy(&stack->dataMutex);
    pthread_cond_destroy(&stack->hasDataCondVar);
}

/* ******************************************************************************** */

void stackArrayPushInt(struct stackArray *stack, int v){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapRealloc(int, stack->data.integer, stack->currentSize);
    }

    pthread_mutex_lock(&stack->dataMutex);
    stack->data.integer[stack->p++] = v;
    pthread_cond_signal(&stack->hasDataCondVar);
    pthread_mutex_unlock(&stack->dataMutex);
}

/* ******************************************************************************** */

void stackArrayPushTreeNode(struct stackArray *stack, struct treeNode* tnode){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapArrayRealloc(struct treeNode, stack->data.treeNode, stack->currentSize);
    }

    pthread_mutex_lock(&stack->dataMutex);
    stack->data.treeNode[stack->p++] = tnode;
    pthread_cond_signal(&stack->hasDataCondVar);
    pthread_mutex_unlock(&stack->dataMutex);
}

/* ******************************************************************************** */

int stackArrayPopInt(struct stackArray *stack){
    pthread_mutex_lock(&stack->dataMutex);

    if(stackArrayIsEmpty(stack))
        pthread_cond_wait(&stack->hasDataCondVar, &stack->dataMutex);

    int value = stack->data.integer[--stack->p];
    pthread_mutex_unlock(&stack->dataMutex);

    return value;
}

/* ******************************************************************************** */

struct treeNode* stackArrayPopTreeNode(struct stackArray *stack){
    pthread_mutex_lock(&stack->dataMutex);

    if(stackArrayIsEmpty(stack))
        pthread_cond_wait(&stack->hasDataCondVar, &stack->dataMutex);
        
    struct treeNode* tnode = stack->data.treeNode[--stack->p];
    pthread_mutex_unlock(&stack->dataMutex);

    return tnode;
}

/* ******************************************************************************** */

int stackArrayIsEmpty(struct stackArray *stack){
    pthread_mutex_lock(&stack->ptrMutex);
    int empty = !stack->p;
    pthread_mutex_unlock(&stack->ptrMutex);

    return empty;
}

/* ******************************************************************************** */

int stackArraySize(struct stackArray *stack){
    pthread_mutex_lock(&stack->dataMutex);
    int size = stack->p > 0 ? stack->p - 1 : 0;
    pthread_mutex_unlock(&stack->dataMutex);

    return size;
}

/* ******************************************************************************** */