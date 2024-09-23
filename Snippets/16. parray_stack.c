#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};

struct node **key_array;
int *next;
int current, head, z;

struct node *n_alloc(){
    return (struct node*)malloc(sizeof(struct node*));
}

struct node *nalloc_i(int value){
    struct node *n = (struct node*)malloc(sizeof(struct node*));
    n->key = value;
    return n;
}

void stack_init(int size){
    key_array = malloc(size*sizeof(struct node*));
    next = (int*)malloc(size*sizeof(int));

    head = 0;
    z = 1;
    current = 2;

    next[head] = z;
    next[z] = z;
}

void push(int v){
    struct node *new = nalloc_i(v);
    key_array[current] = new;

    next[current] = next[head];
    next[head] = current;

    current++;
}

int is_empty(){
    return current == 2;
}

struct node* pop(){
    if(is_empty())
        return NULL;

    struct node *ret = key_array[next[head]];

    current = next[head];
    next[head] = next[current];
    next[current] = 0;

    return ret;
}

void stack_deinit(){
    next[head] = 0;
    next[z] = 0;

    head = 0;
    z = 0;
    current = 0;

    free(key_array);
}

int main(){
    int stack_size = 250;

    stack_init(stack_size);

    for(int i = 0; i < stack_size; i++)
        push(i*10);

    for(int i = 0; i < stack_size; i++)
        printf("%d\n", pop()->key);

    stack_deinit();

    putchar(10);
}