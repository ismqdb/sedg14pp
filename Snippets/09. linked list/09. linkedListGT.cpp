/* ******************************************************************************** */

#include "09. linkedListGT.hpp"

/* ******************************************************************************** */

template<typename T>
    void linkedList<T>::removeCS101(node<T> *target){
        cur = this->head;
        prev = NULL;

        while (cur != target) {
            prev = cur;
            cur = cur->next;
        }
        if (prev)
            prev->next = cur->next;
        else
            this->head = cur->next;
    }

template<typename T>
    void linkedList<T>::removeElegant(node<T> *target){
        node<T> **p = findIndirect(target);
        *p = target->next;
    }

/* ******************************************************************************** */

template<typename T>
    void linkedList<T>::exchange(node<T> *t, node<T> *u){
        if(t == NULL || u == NULL || t > u)
            throw;

        node<T>** leftPrev = findIndirectPrev(t);
        node<T>** rightPrev = findIndirectPrev(u);

        node<T>* leftNext = t->next;
        node<T>* rightNext = u->next;

        if(leftPrev != NULL)
            (*leftPrev)->next = NULL;

        if(rightPrev != NULL)
            if(*rightPrev != NULL)
                (*rightPrev)->next = NULL;

        t->next = NULL;
        u->next = NULL;

        if(leftPrev != NULL){
            if(*leftPrev != NULL)
                (*leftPrev)->next = u;
        }
        else {
            u->next = head;
            head = u;
        }
        u->next = leftNext;

        if(rightPrev != NULL){
            if(*rightPrev != NULL)
                (*rightPrev)->next = t;
        }
        t->next = rightNext;
    }

/* ******************************************************************************** */

template<typename T>
    void linkedList<T>::insertBefore(node<T> *before, node<T> *item){
        node<T> **p = findIndirect(before);
        *p = item;
        item->next = before;
    }

/* ******************************************************************************** */

template<typename T>
    node<T>** linkedList<T>::findIndirect(node<T> *target){
        node<T> **p = &this->head;
        while (*p != target)
                p = &(*p)->next;
        return p;
    }

template<typename T>
    node<T>** linkedList<T>::findIndirectPrev(node<T> *target){
        node<T> **p = &this->head;
        while ((*p)->next != target && (*p)->next != NULL)
                p = &(*p)->next;

        if((*p)->next == NULL)
            return NULL;
        else
            return p;
    }

/* ******************************************************************************** */

template<typename T>
    void linkedList<T>::append(node<T> *item){
        if(this->head == NULL){
            this->head = item;
            this->currentsize++;
            return;
        }

        node<T> **p = &this->head;

        while((*p)->next != NULL)
            p = &(*p)->next;

        (*p)->next = item;
        this->currentsize++;
    }

template<typename T>
    void linkedList<T>::prepend(node<T> *item){
        node<T> **p = &this->head;

        item->next = *p;
        *p = item;
        this->currentsize++;
    }

/* ******************************************************************************** */

template<typename T>
    size_t linkedList<T>::size(){
        return this->currentsize;
    }

template<typename T>
    void linkedList<T>::print(){
        node<T> *temp = this->head;

        while(temp != NULL){
            std::cout << temp->value << ' ';
            temp = temp->next;
        }

        putchar(10);
    }

/* ******************************************************************************** */

template<typename T>
    linkedList<T>::linkedList(){
        head = NULL;
        cur = new node<T>{};
        prev = new node<T>{};
    }

template<typename T>
    linkedList<T>::~linkedList(){
        delete(head);
        delete(cur);
        delete(prev);
    }

/* ******************************************************************************** */