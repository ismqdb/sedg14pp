/* ******************************************************************************** */

#include "./parseTree.hpp"

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

int isNewLevel(int *nodesPerLevel, int nodesVisited){
    int count = 0;

    for(int i = 1; nodesPerLevel[i] != 0; i++){
        count += nodesPerLevel[i];

        if(count == nodesVisited)
            return 1;
    }

    return 0;
}

/* ******************************************************************************** */

template<>
    void drawBinaryTreeIterative(treeNode<char> *t, drawBinaryTreeInfo& drawInfo){
        putchar(10);

        std::queue<treeNode<char>*> queue;
        queue.push(t);

        for(int i = 0; i < drawInfo.offset; i++)
            putchar(0x20);

        while(!queue.empty()){
            if(isNewLevel(drawInfo.nodesPerLevel, drawInfo.nodesVisited)){
                drawInfo.currentLevel++;
                drawInfo.distance /= 2;
                drawInfo.offset = ((drawInfo.offset+1)/2)-1;
                putchar(10);
                for(int i = 0; i < drawInfo.offset; i++)
                    putchar(0x20);
                drawInfo.firstLetterInRow = 1;
            }
            
            drawInfo.nodesVisited++;

            t = queue.front();
            queue.pop();

            if(!drawInfo.firstLetterInRow)
                for(int i = 0; i < drawInfo.distance-1; i++)
                    putchar(0x20);

            if(drawInfo.firstLetterInRow)
                drawInfo.firstLetterInRow = 0;

            if(t != NULL)
                putchar(t->info);
            else
                putchar('.');

            if(t != NULL){
                queue.push(t->left);
                queue.push(t->right);
                drawInfo.nodesPerLevel[drawInfo.currentLevel+1] += 2;
            }
        }

        putchar(10);
    }

/* ******************************************************************************** */

template<>
    void drawBinaryTreeRecursive(treeNode<char> *t, drawBinaryTreeInfo& drawInfo){
        
    }

/* ******************************************************************************** */