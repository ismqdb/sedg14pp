#include <stdlib.h>

static int* queue;
static int head;
static int tail;
static int chuckSize = 25;
static int currentSize = 0;

void put(int v){
    if(tail == currentSize){
        currentSize += chuckSize;
        queue = (int*)realloc(queue, currentSize*sizeof(int));
    }
    queue[tail++] = v;
}

int get(){
    int t = queue[head++];
    if(head == tail){
        head = 0;
        tail = 0;
    }
    return t;
}

void queueinit(int size){
    if(size <= 0)
        return;
    currentSize = size;
    queue = (int*)malloc(currentSize*sizeof(int));
    head = 0;
    tail = 0;
}

int queueempty(){
    return head == tail;
}

void queuedeinit(){
    head = 0;
    tail = 0;
    free(queue);
}