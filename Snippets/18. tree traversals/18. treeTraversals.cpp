/* ******************************************************************************** */

#include "./18. treeTraversals.hpp"

/* ******************************************************************************** */

template<typename T>
    void levelOrderTraversal(treeNode<T> *t){
        std::queue<treeNode<T>*> queue;

        queue.push(t);

        while(!queue.empty()){
            t = queue.front();
            queue.pop();
            
            visit(t);

            if(t->left != NULL)
                queue.push(t->left);

            if(t->right != NULL)
                queue.push(t->right);
        }
    }

/* ******************************************************************************** */

template<>
    void preorderTraversal(treeNode<i8> *t){
        std::stack<treeNode<i8>*> stack{};

        stack.push(t);

        while(!stack.empty()){
            t = stack.top();
            stack.pop();

            visit(t);

            if(t->right != NULL)
                stack.push(t->right);

            if(t->left != NULL)
                stack.push(t->left);
        }
    }

/* ******************************************************************************** */

template<typename T>
    void inorderTraversal(treeNode<T> *t){
        std::stack<treeNode<T>*> stack{};
        treeNode<T> *temp;
        
        do {
            if(t->left != NULL){
                temp = t->left;
                t->left = NULL;
                stack.push(t);
                t = temp;
            } else {
                visit(t);
                t = stack.top();
                stack.pop();
                
                if(t->right != NULL){
                    stack.push(t->right);
                    t->right = NULL;
                }
            }
        } while(!stack.empty());
    }

/* ******************************************************************************** */

template<typename T>
    void postorderTraversal(treeNode<T> *t){
        std::stack<treeNode<T>*> stack{};
        treeNode<T> *temp;

        do {
            if(t->left != NULL && t->right != NULL){
                temp = t->right;
                t->right = NULL;
                stack.push(t);
                stack.push(temp);
                t = t->left;
            } else {
                visit(t);
                t = stack.top();
                stack.pop();
            }
        } while(!stack.empty());

        visit(t);
    }

/* ******************************************************************************** */

template<>
    void preorderIterative(treeNode<i8> *t){
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
    void preorderRecursive(treeNode<i8> *t){
        if(t != NULL){
            visit(t);
            preorderRecursive(t->left);
            preorderRecursive(t->right);
        }
    }

template<typename T>
    void inorderRecursive(treeNode<T> *t){
        if(t != NULL){
            inorderRecursive(t->left);
            visit(t);
            inorderRecursive(t->right);
        }
    }

/* ******************************************************************************** */