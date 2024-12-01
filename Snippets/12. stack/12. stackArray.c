/* ******************************************************************************** */

#include "./12. stackArray.h"

/* ******************************************************************************** */

void stackArrayPushInt(struct stackArray *stack, int v){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        stack->data.integer = (int*)realloc(stack->data.integer, stack->currentSize*sizeof(int));
    }
    stack->data.integer[stack->p++] = v;
}

/* ******************************************************************************** */

void stackArrayPushTreeNode(struct stackArray *stack, struct treeNode* t_node){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        stack->data.treeNode = (struct treeNode**)realloc(stack->data.treeNode, stack->currentSize*sizeof(struct treeNode));
    }
    stack->data.treeNode[stack->p++] = t_node;
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

struct stackArray stackArrayInit(treeNodeDataType type, int size){
    struct stackArray stack;
    stack.currentSize = 0;
    stack.chunkSize = 25;
    stack.type = type;

    switch(type){
        case INT:
            stack.data.integer = (int*)malloc(size*sizeof(int));
            break;
        case TREE_NODE:
            stack.data.treeNode = (struct treeNode**)malloc(size*sizeof(struct treeNode));
            break;
    }

    stack.p = 0;
    stack.currentSize += size;

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