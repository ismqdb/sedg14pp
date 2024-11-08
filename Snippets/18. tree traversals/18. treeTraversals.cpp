/* ******************************************************************************** */

#include "./18. treeTraversals.hpp"

/* ******************************************************************************** */

void levelOrderTraversal(node *t){
    std::queue<node*> queue;

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

void preorderTraversal(node *t){
    std::stack<node*> stack{};

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

void inorderTraversal(node *t){
    std::stack<node*> stack{};
    node *temp;
    
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

void postorderTraversal(node *t){
    std::stack<node*> stack{};
    node *temp;

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

void preOrderIterative(treeNode *t){
    std::stack<treeNode*> stack{};

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

void prerderRecursive(treeNode *t){
    if(t != NULL){
        treeNodeVisit(t);
        pre_order_recursive(t->left);
        pre_order_recursive(t->right);
    }
}

void inorderRecursive(treeNode *t){
    if(t != NULL){
        pre_order_recursive(t->left);
        treeNodeVisit(t);
        pre_order_recursive(t->right);
    }
}

/* ******************************************************************************** */