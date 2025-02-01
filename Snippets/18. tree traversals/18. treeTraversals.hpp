/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <queue>

#include "../00. includes/tree node/treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    void levelOrderTraversal(treeNode<T>*);

template<typename T>
    void preorderTraversal(treeNode<T>*);

template<typename T>
    void inorderTraversal(treeNode<T>*);

template<typename T>
    void postorderTraversal(treeNode<T>*);

template<typename T>
    void preorderIterative(treeNode<T>*);

template<typename T>
    void preorderRecursive(treeNode<T>*);

template<typename T>
    void inorderRecursive(treeNode<T>*);

/* ******************************************************************************** */

template<> void preorderTraversal<char>(treeNode<char>*);
template<> void preorderIterative<char>(treeNode<char>*);
template<> void preorderRecursive<char>(treeNode<char>*);

/* ******************************************************************************** */