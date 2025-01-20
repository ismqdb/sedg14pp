/* ******************************************************************************** */

#include "./22. recursionRemovalInOrder.hpp"

/* ******************************************************************************** */

template<typename T>
    void inOrderRR0(treeNode<T> *t){
        if(t != NULL){
            inOrderRR0(t->left);
            visitTreeNode(t);
            inOrderRR0(t->right);
        }
    }

/* ******************************************************************************** */

template<typename T>
    void inOrderRR1(treeNode<T> *t){
        std::stack<treeNode<T>> stack;

        l:
            if(t == NULL)
                goto r;

            stack.push(t);
            t = t->left;
            goto l;

        r:
            t = stack.top();
            stack.pop();
            visitTreeNode(t);

            if(t->right == NULL){
                if(stack.empty())
                    goto x;
            }
            else {
                t = t->right;
                goto l;
            }

            goto r;

        x:
            return;
    }

/* ******************************************************************************** */