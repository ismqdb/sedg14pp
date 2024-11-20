/* ******************************************************************************** */

#include "./treeNodeRS.hpp"

/* ******************************************************************************** */

template<typename T>
    void visit(treeNodeRS<T> *node){
        std::cout << node->value << ' ';
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
        treeNodeRS<char>* t;

        queue.push(node);

        while(1){
            node = queue.front();
            queue.pop();

            t = node;

            visit<char>(t);
            std::flush(std::cout);

            while(t->sibling != NULL){
                t = t->sibling;
                queue.push(t);
            }

            if(node->child)
                queue.push(node->child);
        }
    }

/* ******************************************************************************** */