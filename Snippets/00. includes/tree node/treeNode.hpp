/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include <utility>
#include <vector>
#include <algorithm>

#include "../types.hpp"

/* ******************************************************************************** */

template<typename T>
    struct treeNode {
        T value;
        treeNode* left;
        treeNode* right;
    };

/* ******************************************************************************** */

template<typename T>
    void drawBinaryTreeRecursive(
        treeNode<T>*,
        std::vector<std::pair<treeNode<T>*, i32>>&,
        i32, i32);

template<typename T>
    void externalPathLength(treeNode<T>*, i32, i32&);

i32 drawBinaryTreeRecursiveDriver();

template<typename T>
    void visit(treeNode<T>*);

/* ******************************************************************************** */

template struct treeNode<i8>;

template<> void visit(treeNode<i8>*);

/* ******************************************************************************** */