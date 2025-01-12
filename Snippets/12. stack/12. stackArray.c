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

    pthread_mutex_init(&stack.mutex, NULL);
    pthread_cond_init(&stack.emptyCondVar, NULL);

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

    pthread_mutex_destroy(&stack->mutex);
    pthread_cond_destroy(&stack->emptyCondVar);
}

/* ******************************************************************************** */

void stackArrayPushInt(struct stackArray *stack, int v){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapRealloc(int, stack->data.integer, stack->currentSize);
    }
    stack->data.integer[stack->p++] = v;
}

/* ******************************************************************************** */

void stackArrayPushTreeNode(struct stackArray *stack, struct treeNode* tnode){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapArrayRealloc(struct treeNode, stack->data.treeNode, stack->currentSize);
    }
    stack->data.treeNode[stack->p++] = tnode;
}

/* ******************************************************************************** */

int stackArrayPopInt(struct stackArray *stack){
    return stack->data.integer[--stack->p];
}

/* ******************************************************************************** */

struct treeNode* stackArrayPopTreeNode(struct stackArray *stack){
    return stack->data.treeNode[--stack->p];
}

/* ******************************************************************************** */

int stackArrayIsEmpty(struct stackArray *stack){
    return !stack->p;
}

/* ******************************************************************************** */

int stackArraySize(struct stackArray *stack){
    return stack->p > 0 ? stack->p - 1 : 0;
}

/* ******************************************************************************** */