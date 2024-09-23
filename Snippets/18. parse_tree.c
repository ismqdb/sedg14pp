#include <stdio.h>
#include <stdlib.h>

struct node {
    char info;
    struct node *left;
    struct node *right;
};

struct node *nalloc(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node *x;
struct node *z;
char c;

void stackinit(){
    x = nalloc();
    z = nalloc();


}

void push(struct node *x){

}

struct node* pop(){
    
}

int main(){
    z = nalloc();
    z->left = z;
    z->right = z;

    for(stackinit(); (c = getchar()) != EOF;){
        x = nalloc();
        x->info = c;
        x->left = z;
        x->right = z;
        if(c == '+' || c == '*'){
            x->right = pop();
            x->left = pop();
        }
        push(x);
    }

    putchar(10);
}