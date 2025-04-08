/* ******************************************************************************** */

#include "./treeNodeRS.hpp"

/* ******************************************************************************** */

template<typename T>
    void visit(treeNodeRS<T> *node){
        std::cout << node->value << ' ';
    }

/* ******************************************************************************** */

template<>
    treeNodeRS<i8> *createNode(i8 value){
        treeNodeRS<i8> *t = new treeNodeRS<i8>;
        t->value = value;
        return t;
    }

/* ******************************************************************************** */

template<>
    treeNodeRS<i8>* insertChild(treeNodeRS<i8> *node, i8 value){
        auto x = createNode<i8>(value);
        node->child = x;
        return x;
    }

/* ******************************************************************************** */

template<>
    treeNodeRS<i8>* insertSibling(treeNodeRS<i8> *parent, treeNodeRS<i8> *node, i8 value){
        auto x = createNode<i8>(value);

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
    void levelOrderTraversal(treeNodeRS<i8> *node){
        std::queue<treeNodeRS<i8>*> queue;
        treeNodeRS<i8> *temp1, *temp2;

        queue.push(node);

        while(!queue.empty()){
            node = queue.front();
            queue.pop();

            visit<i8>(node);
            std::flush(std::cout);

            if(node->sibling){
                temp1 = node;
                while(1){
                    temp2 = temp1->sibling;
                    temp1->sibling = NULL;
                    queue.push(temp2);

                    if(!temp2->sibling)
                        break;

                    temp1 = temp2;
                }
            }

            if(node->child)
                queue.push(node->child);
        }

        std::cout << '\n';
    }

/* ******************************************************************************** */

template<>
    void externalPathLengthRS(treeNodeRS<i8>* t, i32 level, i32 &result){
        if(!t) return;

        if(t->child || t->sibling)
            level++;

        if(t->child)
            externalPathLengthRS(t->child, level, result);
        else
            result += level;

        if(t->sibling)
            externalPathLengthRS(t->sibling, level, result);
        else
            result += level;
    }

/* ******************************************************************************** */