#include "./treeNode.hpp"
#include "../parse tree/parseTree.hpp"

template<>
    none visit(treeNode<i8>* node){
        std::cout << node->value << ' ';
    }

template<typename T>
    none drawBinaryTreeRecursive(
        treeNode<T>* t,
        std::vector<std::pair<treeNode<T>*, i32>>& pairs,
        i32 left, i32 right){
            if(t == NULL)
                return;
            else {
                auto x = std::make_pair(t, (left+right)/2);
                pairs.push_back(x);
            }

            if(t->left != NULL){
                i32 middle = (left+right)/2;
                drawBinaryTreeRecursive(t->left, pairs, left, middle);
            }

            if(t->right != NULL){
                i32 middle = (left+right)/2;
                drawBinaryTreeRecursive(t->right, pairs, middle, right);
            }
    }

template<typename T>
    none externalPathLength(treeNode<T>* t, i32 level, i32& len){
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

i32 drawBinaryTreeRecursiveDriver(){
    i32 screenWidth = 80;

    treeNode<i8> *t = buildParseTree<i8>();

    std::vector<std::pair<treeNode<i8>*, i32>> pairs;

    drawBinaryTreeRecursive<i8>(t, pairs, 0, screenWidth);

    std::sort(pairs.begin(), pairs.end(), 
    [](
        std::pair<treeNode<i8>*, i32> p1,
        std::pair<treeNode<i8>*, i32> p2){
            return p1.second < p2.second;
        }
    );

    std::cout << std::endl;
    for(i32 pos = 0, printed = 0; pos < screenWidth; pos++){
        if(pairs[printed].second == pos)
            std::cout << pairs[printed++].first->value;
        else
            std::cout << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;

    return 1;
}