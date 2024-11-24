/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include <utility>
#include <vector>
#include <algorithm>

/* ******************************************************************************** */

template<typename T>
    struct treeNode {
        T info;
        treeNode* left;
        treeNode* right;
    };

/* ******************************************************************************** */

template<typename T>
    void drawBinaryTreeRecursive(
        treeNode<T>*,
        std::vector<std::pair<treeNode<T>*, int>>&,
        int, int);

template<typename T>
    void externalPathLength(treeNode<T>*, int, int&);

int drawBinaryTreeRecursiveDriver();

template<typename T>
    void visit(treeNode<T>);

/* ******************************************************************************** */