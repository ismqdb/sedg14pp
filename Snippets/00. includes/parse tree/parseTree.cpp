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

template<>
    void drawBinaryTreeRecursive<char>(
        treeNode<char>* t,
        std::vector<std::pair<treeNode<char>*, int>>& pairs,
        int left, int right){
            if(t == NULL)
                return;
            else {
                auto x = std::make_pair(t, (left+right)/2);
                pairs.push_back(x);
            }

            if(t->left != NULL){
                int middle = (left+right)/2;
                drawBinaryTreeRecursive(t->left, pairs, left, middle);
            }

            if(t->right != NULL){
                int middle = (left+right)/2;
                drawBinaryTreeRecursive(t->right, pairs, middle, right);
            }
    }

/* ******************************************************************************** */

int drawBinaryTreeRecursiveDriver(){
    int screenWidth = 80;

    treeNode<char> *t = buildParseTree<char>();

    std::vector<std::pair<treeNode<char>*, int>> pairs;

    drawBinaryTreeRecursive<char>(t, pairs, 0, screenWidth);

    std::sort(pairs.begin(), pairs.end(), 
    [](
        std::pair<treeNode<char>*, int> p1,
        std::pair<treeNode<char>*, int> p2){
            return p1.second < p2.second;
        }
    );

    std::cout << std::endl;
    for(int pos = 0, printed = 0; pos < screenWidth; pos++){
        if(pairs[printed].second == pos)
            std::cout << pairs[printed++].first->info;
        else
            std::cout << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    return 1;
}

/* ******************************************************************************** */