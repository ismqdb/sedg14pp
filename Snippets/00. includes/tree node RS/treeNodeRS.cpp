/* ******************************************************************************** */

#include "./treeNodeRS.hpp"

/* ******************************************************************************** */

template<typename T>
    void visit(treeNodeRS<T> node){
        std::cout << node->info << ' ';
    }

/* ******************************************************************************** */

template<>
    treeNodeRS<char> *createNode(char value){
        treeNodeRS<char> *t = new treeNodeRS<char>;
        t->value = value;
        return t;
    }

/* ******************************************************************************** */

template<>
    void insertChild(treeNodeRS<char> *node, char value){
        auto x = createNode<char>(value);
        x->parent = node;
        node->child = x;
    }

/* ******************************************************************************** */

template<>
    void insertSibling(treeNodeRS<char> *node, char value){
        auto x = createNode<char>(value);

        auto it = node;

        while(it->sibling != NULL){
            it = it->sibling;
            it->parent = NULL;
        }

        it->sibling = x;
        it->sibling->parent = node;
    }

/* ******************************************************************************** */

template<>
    void levelOrderTraversal(treeNodeRS<char> *node){
        std::queue<treeNodeRS<char>*> queue;
    }

/* ******************************************************************************** */