/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include "../tree node/treeNode.hpp"

/* ******************************************************************************** */

struct drawBinaryTreeInfo {
    drawBinaryTreeInfo(int);

    int screenWidth;
    int nodesVisited;
    int currentLevel;

    /* Distance between two symbols on the same row. */
    int distance = screenWidth;

    /* Offset to the first letter from terminal start */
    int offset = (screenWidth/2)-1;
    int firstLetterInRow = true;
    int nodesPerLevel[100] = {0};
};

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree();

int isNewLevel(int*, int);

template<typename T>
    void drawBinaryTreeIterative(std::queue<treeNode<char>*>&, drawBinaryTreeInfo&);

template<typename T>
    void drawBinaryTreeRecursive(std::queue<treeNode<char>*>&, drawBinaryTreeInfo&);

/* ******************************************************************************** */