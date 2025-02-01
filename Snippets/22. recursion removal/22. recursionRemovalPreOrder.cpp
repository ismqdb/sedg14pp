/* ******************************************************************************** */

#include "./22. recursionRemovalPreOrder.hpp"

/* ******************************************************************************** */

template<typename T>
    void preOrderRR0(treeNode<T> *t){
        if(t != NULL){
            visitTreeNode(t);
            preOrderRR0(t->left);
            preOrderRR0(t->right);
        }
    }

/* ******************************************************************************** */

template<typename T>
    void preOrderRR1(treeNode<T> *t){
        l:
            if(t == NULL)
                goto x;
            visitTreeNode(t);
            preOrderRR1(t->left);
            t = t->right;
            goto l;
        
        x:
            ;
    }

/* ******************************************************************************** */

template<typename T>
    void preOrderRR2(treeNode<T> *t){
        std::stack<treeNode<T>> stack;

        l:
            if(t == NULL)
                goto s;
            visitTreeNode(t);
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
            stackArrayDeinit(&stack);
    }

/* ******************************************************************************** */

template<typename T>
    void preOrderRR3(treeNode<T> *t){
        std::stack<treeNode<T>> stack;

        l:
            while(t != NULL){
                visitTreeNode(t);
                stack.push(t->right);
                t = t->left;
            }

            if(stack.empty())
                goto x;

            t = stack.top();
            stack.pop();
            goto l;

        x: 
            stackArrayDeinit(&stack);
    }

/* ******************************************************************************** */

template<>
    void preOrderRR4(treeNode<char> *t){
        std::stack<treeNode<char>*> stack{};

        stack.push(t->right);

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
    void preOrderRR4Inline(treeNode<char> *t){
        stackA<treeNode<char>*> stack{};

        stack.push(t->right);

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