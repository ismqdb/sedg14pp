/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

struct node {
    public:
        node(int val) : key{val}, next{NULL}{}
        node() : key{0}, next{NULL}{}

        int key;
        struct node *next;
};

/* ******************************************************************************** */

class queueL {
    public:
        queueL();
        ~queueL();

        void put(int);
        node* get();
        bool isEmpty();
    private:
        node *head;
        node *current;
};

/* ******************************************************************************** */

queueL::queueL(){
    this->head = NULL;
    this->current = NULL;
}

queueL::~queueL(){

}

/* ******************************************************************************** */

void queueL::put(int value){
    node *item = new node{value};

    if(this->head == NULL){
        this->head = item;
        this->current = this->head;
        return;
    }

    current->next = item;
    current = current->next;

    item = NULL;
    delete(item);
}

node* queueL::get(){
    node *item = this->head;

    this->head = this->head->next;
    return item;
}

/* ******************************************************************************** */

bool queueL::isEmpty(){
    return this->head == NULL;
}

/* ******************************************************************************** */

int main(){
    queueL queue{};

    int size = 10;

    for(int i = 0; i < size; i++)
        queue.put(i*i);

    while(!queue.isEmpty())
        std::cout << queue.get()->key << '\n';
}

/* ******************************************************************************** */