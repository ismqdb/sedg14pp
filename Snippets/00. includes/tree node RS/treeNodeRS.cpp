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
        treeNodeRS<char> *temp1, *temp2;

        queue.push(node);

        while(!queue.empty()){
            node = queue.front();
            queue.pop();

            visit<char>(node);
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
    void externalPathLength(treeNodeRS<char>* t, int level, int &result){
        
    }

/* ******************************************************************************** */