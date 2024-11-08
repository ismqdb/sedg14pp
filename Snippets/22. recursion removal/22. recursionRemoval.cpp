#include "./22. recursionRemoval.hpp"

template<typename T>
    void traversePreorder(treeNode<T> *t){
        if(t != NULL){
            visit(t);
            traverse_preorder(t->left);
            traverse_preorder(t->right);
        }
    }

template<typename T>
    void removeRecursion1(treeNode<T> *t){
        l:
            if(t == NULL)
                goto x;
            visit(t);
            removeRecursion1(t->left);
            t = t->right;
            goto l;
        
        x:
            ;
    }

template<typename T>
    void removeRecursion2(treeNode<T> *t){
        std::stack<treeNode<T>*> stack;

        l:
            if(t == NULL)
                goto s;
            visit(t);
            stack.push(t->right);
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

template<typename T>
    void removeRecursion3(treeNode<T> *t){
        std::stack<treeNode<T>*> stack;

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

template<typename T>
    void removeRecursion4(treeNode<T> *t){
        std::stack<treeNode<T>*> stack;

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