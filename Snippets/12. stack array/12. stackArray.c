/* ******************************************************************************** */

#include "./12. stackArray.h"

/* ******************************************************************************** */

void stackArrayPushInt(stackArray *stack, int v){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        stack->data.integer = (int*)realloc(stack->data.integer, stack->currentSize*sizeof(int));
    }
    stack->data.integer[stack->p++] = v;
}

/* ******************************************************************************** */

void stackArrayPushTreeNode(stackArray *stack, treeNode* t_node){
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        stack->data.treeNode = (treeNode**)realloc(stack->data.treeNode, stack->currentSize*sizeof(treeNode));
    }
    stack->data.treeNode[stack->p++] = t_node;
}

/* ******************************************************************************** */

int stackArrayPopInt(stackArray *stack){
    return stack->data.integer[--stack->p];
}

/* ******************************************************************************** */

treeNode* stackArrayPopTreeNode(stackArray *stack){
    return stack->data.treeNode[--stack->p];
}

/* ******************************************************************************** */

stackArray stackArrayInit(treeNodeDataType type, int size){
    stackArray stack;
    stack.currentSize = 0;
    stack.chunkSize = 25;
    stack.type = type;

    switch(type){
        case INT:
            stack.data.integer = (int*)malloc(size*sizeof(int));
            break;
        case TREE_NODE:
            stack.data.treeNode = (treeNode**)malloc(size*sizeof(treeNode));
            break;
    }

    stack.p = 0;
    stack.currentSize += size;

    return stack;
}

/* ******************************************************************************** */

void stackArrayDeinit(stackArray *stack){
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

int stackArrayIsEmpty(stackArray *stack){
    return !stack->p;
}

/* ******************************************************************************** */

int stackArraySize(stackArray *stack){
    return stack->p > 0 ? stack->p - 1 : 0;
}

/* ******************************************************************************** */