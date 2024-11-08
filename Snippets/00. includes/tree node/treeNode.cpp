/* ******************************************************************************** */

#include "./treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>::treeNode(T value, treeNode<T> *l, treeNode<T> *r){
        this->info = value;
        this->left = l;
        this->right = r;
    }

/* ******************************************************************************** */

template<typename T>
    void treeNode<T>::visit(){
        if(this->info == NULL)
            return;
        
        std::cout << t->info << ' ';
    }

/* ******************************************************************************** */