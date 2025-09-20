#include "./22. recursionRemovalInOrder.hpp"

template<typename T>
    none inOrderRR0(treeNode<T> *t){
        if(t != NULL){
            inOrderRR0(t->left);
            visit(t);
            inOrderRR0(t->right);
        }
    }

template<typename T>
    none inOrderRR1(treeNode<T> *t){
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
            visit(t);

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