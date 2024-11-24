/* ******************************************************************************** */

#include "./parseTree.hpp"

/* ******************************************************************************** */

template<>
    treeNode<char>* buildParseTree(){
        treeNode<char> *x;
        char c;

        std::stack<treeNode<char>*> stack{};

        while(1){
            c = getchar();

            if(c == EOF || c == '\n')
                break;

            if(c == '(' || c == ')' || c == ' ')
                continue;

            x = new treeNode<char>{c};

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

        treeNode<char> *returnValue = stack.top();
        stack.pop();
        return returnValue;
    }

/* ******************************************************************************** */