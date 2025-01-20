/* ******************************************************************************** */

#include "./22. recursionRemovalPostOrder.hpp"

/* ******************************************************************************** */

template<typename T>
    void postOrderRR0(treeNode<T> *t){
        if(t != NULL){
            postOrderRR0(t->left);
            postOrderRR0(t->right);
            visitTreeNode(t);
        }
    }

/* ******************************************************************************** */

template<typename T>
    void postOrderRR1(treeNode<T> *t){
        std::stack<T> stack;
        treeNode<T> *temp;

        l:
            if(t == NULL)
                goto r;

            stack.push(t);
            t = t->left;
            goto l;

        r:
            t = stack.top();
            stack.pop();

            if(t->right == NULL){
                if(stack.empty()){
                    visitTreeNode(t);
                    goto x;
                }
            }
            else {
                stack.push(t);
                temp = t->right;
                t->right = NULL;
                t = temp;
                goto l;
            }

            visitTreeNode(t);
            goto r;

        x:
            return;
    }

/* ******************************************************************************** */