/* ******************************************************************************** */

#include "./22. recursionRemovalPostOrder.hpp"

/* ******************************************************************************** */

template<typename T>
    none postOrderRR0(treeNode<T> *t){
        if(t != NULL){
            postOrderRR0(t->left);
            postOrderRR0(t->right);
            visit(t);
        }
    }

/* ******************************************************************************** */

template<typename T>
    none postOrderRR1(treeNode<T> *t){
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
                    visit(t);
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

            visit(t);
            goto r;

        x:
            return;
    }

/* ******************************************************************************** */