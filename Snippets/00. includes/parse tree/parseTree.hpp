/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include "../tree node/treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree();

int isNewLevel(int*, int);

template<typename T>
    void drawBinaryTreeIterative(treeNode<T>*);

template<typename T>
    void drawBinaryTreeRecursive(treeNode<T>*);

/* ******************************************************************************** */