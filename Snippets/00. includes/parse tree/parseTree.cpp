/* ******************************************************************************** */

#include "./parseTree.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree(){
        treeNode<T> *x;
        char c;

        std::stack<treeNode<T>*> stack{};

        while(1){
            c = getchar();

            if(c == EOF || c == '\n')
                break;

            if(c == '(' || c == ')' || c == ' ')
                continue;

            x = new treeNode<T>{c};

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

        treeNode<T> *returnValue = stack.top();
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

template<typename T>
    void drawBinaryTreeIterative(treeNode<T> *t){
        putchar(10);

        const int screenWidth = 80;

        int nodesVisited = 0;
        int currentLevel = 1;

        /* Distance between two symbols on the same row. */
        int distance = screenWidth;

        /* Offset to the first letter from terminal start */
        int offset = (screenWidth/2)-1;

        int firstLetterInRow = 1;

        int nodesPerLevel[100] = {0};
        nodesPerLevel[1] = 1;

        std::queue<treeNode<T>*> queue;
        queue.push(t);

        for(int i = 0; i < offset; i++)
            putchar(0x20);

        while(!queue.empty()){
            if(isNewLevel(nodesPerLevel, nodesVisited)){
                currentLevel++;
                distance /= 2;
                offset = ((offset+1)/2)-1;
                putchar(10);
                for(int i = 0; i < offset; i++)
                    putchar(0x20);
                firstLetterInRow = 1;
            }
            
            nodesVisited++;

            t = queue.front();

            if(!firstLetterInRow)
                for(int i = 0; i < distance-1; i++)
                    putchar(0x20);

            if(firstLetterInRow)
                firstLetterInRow = 0;

            if(t != NULL)
                putchar(t->info);
            else
                putchar('.');

            if(t != NULL){
                queue.push(t->left);
                queue.push(t->right);
                nodesPerLevel[currentLevel+1] += 2;
            }
        }

        putchar(10);
    }

/* ******************************************************************************** */

template<typename T>
    void drawBinaryTreeRecursive(treeNode<T> *t){
        
    }

/* ******************************************************************************** */