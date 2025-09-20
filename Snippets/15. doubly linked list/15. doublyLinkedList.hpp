#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/node/node.hpp"

template<typename T>
    class doublyLinkedList {
        public:
            doublyLinkedList();
            ~doublyLinkedList();

            node<T>* insertAfter(node<T>*, i32);
            none removeNext(node<T>*);
        private:
            node<T> *head;
            node<T> *tail;
    };