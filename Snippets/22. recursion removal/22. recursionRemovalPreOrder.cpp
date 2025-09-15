/* ******************************************************************************** */

#include "./22. recursionRemovalPreOrder.hpp"

/* ******************************************************************************** */

template<typename T>
    none preOrderRR0(treeNode<T> *t){
        if(t != NULL){
            visit(t);
            preOrderRR0(t->left);
            preOrderRR0(t->right);
        }
    }

/* ******************************************************************************** */

template<typename T>
    none preOrderRR1(treeNode<T> *t){
        l:
            if(t == NULL)
                goto x;
            visit(t);
            preOrderRR1(t->left);
            t = t->right;
            goto l;
        
        x:
            ;
    }

/* ******************************************************************************** */

template<typename T>
    none preOrderRR2(treeNode<T> *t){
        std::stack<treeNode<T>> stack;

        l:
            if(t == NULL)
                goto s;
            visit(t);
            stack.push(t);
            t = t->left;
            goto l;

        s:
            if(stack.empty())
                goto x;
            t = stack.top();
            stack.pop();
            goto l;

        x: 
            ;
    }

/* ******************************************************************************** */

template<typename T>
    none preOrderRR3(treeNode<T> *t){
        std::stack<treeNode<T>> stack;

        l:
            while(t != NULL){
                visit(t);
                stack.push(t->right);
                t = t->left;
            }

            if(stack.empty())
                goto x;

            t = stack.top();
            stack.pop();
            goto l;

        x: 
            ;
    }

/* ******************************************************************************** */

template<>
    none preOrderRR4(treeNode<i8> *t){
        std::stack<treeNode<i8>*> stack{};

        stack.push(t);

        while(!stack.empty()){
            t = stack.top();
            stack.pop();

            while(t != NULL){
                visit(t); 
                stack.push(t->right);
                t = t->left;
            }
        }
    }

/* ******************************************************************************** */

template<>
    none preOrderRR4Inline(treeNode<i8> *t){
        stackA<treeNode<i8>*> stack{};

        stack.push(t);

        while(!stack.isEmpty()){
            t = stack.top();
            stack.pop();

            while(t != NULL){
                visit(t); 
                stack.push(t->right);
                t = t->left;
            }
        }
    }

/* ******************************************************************************** */