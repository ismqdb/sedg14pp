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
    treeNodeRS<char>* insertChild(treeNodeRS<char> *node, char value){
        auto x = createNode<char>(value);
        node->child = x;
        return x;
    }

/* ******************************************************************************** */

template<>
    treeNodeRS<char>* insertSibling(treeNodeRS<char> *parent, treeNodeRS<char> *node, char value){
        auto x = createNode<char>(value);

        auto it = node;

        while(it->sibling != NULL){
            it = it->sibling;
        }

        it->sibling = x;
        it->sibling->parent = parent;

        return it->sibling;
    }

/* ******************************************************************************** */

template<>
    void levelOrderTraversal(treeNodeRS<char> *node){
        std::queue<treeNodeRS<char>*> queue;
    }

/* ******************************************************************************** */