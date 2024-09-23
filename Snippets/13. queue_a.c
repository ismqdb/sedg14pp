#include <stdlib.h>

typedef struct queue_a {
    int* queue;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queue_a;

void put(queue_a queue, int v){
    if(queue.tail == queue.current_size){
        queue.current_size += queue.chunk_size;
        queue.queue = (int*)realloc(queue.queue, queue.current_size*sizeof(int));
    }
    queue.queue[queue.tail++] = v;
}

int get(queue_a queue){
    int t = queue.queue[queue.head++];
    if(queue.head == queue.tail){
        queue.head = 0;
        queue.tail = 0;
    }
    return t;
}

queue_a queue_init(int size){
    queue_a queue;
    queue.chunk_size = 25;
    queue.current_size = 0;

    if(size <= 0)
        return;

    queue.current_size = size;
    queue.queue = (int*)malloc(queue.current_size*sizeof(int));
    queue.head = 0;
    queue.tail = 0;

    return queue;
}

int is_queue_empty(queue_a queue){
    return queue.head == queue.tail;
}

void queue_deinit(queue_a queue){
    queue.head = 0;
    queue.tail = 0;
    free(queue.queue);
}