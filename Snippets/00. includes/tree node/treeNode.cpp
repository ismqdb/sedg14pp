/* ******************************************************************************** */

#include "./treeNode.hpp"
#include "../parse tree/parseTree.hpp"

/* ******************************************************************************** */

template<typename T>
    void visit(treeNode<T> node){
        std::cout << node->info << ' ';
    }

/* ******************************************************************************** */

template<typename T>
    void drawBinaryTreeRecursive(
        treeNode<T>* t,
        std::vector<std::pair<treeNode<T>*, int>>& pairs,
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

template<typename T>
    void externalPathLength(treeNode<T>* t, int level, int& len){
        if(t->left || t->right)
            level++;

        if(t->left)
            externalPathLength(t->left, level, len);
        else
            len += level;

        if(t->right)
            externalPathLength(t->right, level, len);
        else
            len += level;
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