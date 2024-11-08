/* ******************************************************************************** */

#include "./18. treeTraversals.hpp"

/* ******************************************************************************** */

template<typename T>
    void levelOrderTraversal(node<T> *t){
        std::queue<node<T>*> queue;

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

template<typename T>
    void preorderTraversal(node<T> *t){
        std::stack<node<T>*> stack{};

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

template<typename T>
    void inorderTraversal(node<T> *t){
        std::stack<node<T>*> stack{};
        node<T> *temp;
        
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

template<typename T>
    void postorderTraversal(node<T> *t){
        std::stack<node<T>*> stack{};
        node<T> *temp;

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

template<typename T>
    void preOrderIterative(treeNode<T> *t){
        std::stack<treeNode<T>*> stack{};

        stack.push(t);

        while(stack_a_is_empty(&stack)){
            t = stack.pop();

            while(t != NULL){
                treeNodeVisit(t);
                stack.push(t->right);
                t = t->left;
            }
        }
    }

template<typename T>
    void prerderRecursive(treeNode<T> *t){
        if(t != NULL){
            treeNodeVisit(t);
            pre_order_recursive(t->left);
            pre_order_recursive(t->right);
        }
    }

template<typename T>
    void inorderRecursive(treeNode<T> *t){
        if(t != NULL){
            pre_order_recursive(t->left);
            treeNodeVisit(t);
            pre_order_recursive(t->right);
        }
    }

/* ******************************************************************************** */