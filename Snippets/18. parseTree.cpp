/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

/* ******************************************************************************** */

struct node {
    public:
        node(char _x)   : info{_x}, left{NULL}, right{NULL}{}
        node()          : info{0}, left{NULL}, right{NULL}{}

        char info;
        node *left;
        node *right;
};

/* ******************************************************************************** */

struct nodeF {
    public:
        nodeF(char _x)  : info{_x}, child{NULL}, sibling{NULL}{}
        nodeF()         : info{0}, child{NULL}, sibling{NULL}{}

        char info;
        nodeF *child;
        nodeF *sibling;
};

/* ******************************************************************************** */

node* buildParseTree(){
    node *x;
    char c;

    std::stack<node*> stack{};

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == '(' || c == ')' || c == ' ')
            continue;

        x = new node{c};

        if(c == '+' || c == '*'){
            if(!stack.empty()){
                x->right = stack.top();
                stack.pop();
            }
            if(!stack.empty()){
                x->left = stack.top();
                stack.pop();
            }
        }

        stack.push(x);
    }

    node *returnValue = stack.top();
    stack.pop();
    return returnValue;
}

/* ******************************************************************************** */

void visit(node *t){
    std::cout << t->info << ' ';
}

/* ******************************************************************************** */

void visit(nodeF *t){
    std::cout << t->info << ' ';
}

/* ******************************************************************************** */

void levelOrderTraversal(nodeF *t){
    std::queue<nodeF*> queue;

    queue.push(t);

    while(t != NULL){
        t = queue.front();
        queue.pop();

        queue.push(t->child);

        while(t != NULL){
            visit(t);
            t = t->sibling;
        }
    }
}

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

int main(){
    // A * (((B+C) * (D*E)) + F)
    // A B C + D E * * F + *
    node *root = buildParseTree();
    levelOrderTraversal(root);
    preorderTraversal(root);

    putchar(10);
}

/* ******************************************************************************** */