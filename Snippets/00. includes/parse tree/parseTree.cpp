/* ******************************************************************************** */

#include "./parseTree.hpp"

#define DEBUG 1

/* ******************************************************************************** */

drawBinaryTreeInfo::drawBinaryTreeInfo(int screenWidth){
    this->screenWidth = screenWidth;
    this->nodesVisited = 0;
    this->currentLevel = 1;
    this->distance = screenWidth;
    this->offset = (this->screenWidth/2)-1;
    this->firstLetterInRow = true;
    this->nodesPerLevel[1] = 1;
}

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

void updateDrawInfo(drawBinaryTreeInfo& drawInfo){
    drawInfo.currentLevel++;
    drawInfo.distance /= 2;
    drawInfo.offset = ((drawInfo.offset+1)/2)-1;
    drawInfo.firstLetterInRow = 1;
}

/* ******************************************************************************** */

template<>
    void drawBinaryTreeRecursive<char>(treeNode<char>* t, drawBinaryTreeInfo drawInfo){

    }

/* ******************************************************************************** */