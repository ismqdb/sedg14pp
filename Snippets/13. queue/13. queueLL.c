/* ******************************************************************************** */

#include "./13. queueLL.h"

/* ******************************************************************************** */

struct queueArray queueLLInit(){
    struct queueArray queue;
    queue.head = NULL;

    return queue;
}

/* ******************************************************************************** */

void queueLLPutInt(struct queueArray *queue, int value){
    node *item = nodeAlloc(value);
    node **p = &queue->head;

    if(queue->head == NULL){
        queue->head = item;
        return;
    }

    while((*p) != NULL)
        //*p = (*p)->next;
        p = &(*p)->next;

    (*p) = item;
}

/* ******************************************************************************** */

node* queueLLGetNode(struct queueArray *queue){
    node *item = queue->head;

    queue->head = queue->head->next;
    return item;
}

/* ******************************************************************************** */

int queueLLIsEmpty(struct queueArray *queue){
    return queue->head == NULL;
}

/* ******************************************************************************** */