/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include <utility>
#include <vector>
#include <algorithm>

#include "../tree node/treeNode.hpp"
#include "../n ary tree/nAryTree.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree();

template<typename T>
    void drawBinaryTreeRecursive(
        treeNode<T>*,
        std::vector<std::pair<treeNode<char>*, int>>&,
        int, int);

template<typename T>
    void externalPathLength(treeNode<T>*, int, int&);

int drawBinaryTreeRecursiveDriver();

/* ******************************************************************************** */