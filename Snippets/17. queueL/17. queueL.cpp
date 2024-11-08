/* ******************************************************************************** */

#include "./17. queueL.hpp"

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