/* ******************************************************************************** */

#include "./treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode::treeNode(T value, treeNode<T> *l, treeNode<T> *r){
        this->info = value;
        this->left = l;
        this->right = r;
    }

/* ******************************************************************************** */

template<typename T>
    void treeNode::visit(){
        if(this->info == NULL)
            return;
        
        std::cout << t->info << ' ';
    }

/* ******************************************************************************** */