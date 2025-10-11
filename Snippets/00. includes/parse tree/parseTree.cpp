/* ******************************************************************************** */

#include "./parseTree.hpp"

/* ******************************************************************************** */

template<>
    treeNode<i8>* buildParseTree(){
        treeNode<i8> *x;
        i8 c;

        std::stack<treeNode<i8>*> stack{};

        while(1){
            c = getchar();

            if(c == EOF || c == '\n')
                break;

            if(c == '(' || c == ')' || c == ' ')
                continue;

            x = new treeNode<i8>{c};

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

        treeNode<i8> *returnValue = stack.top();
        stack.pop();
        return returnValue;
    }

/* ******************************************************************************** */