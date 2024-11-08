/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <queue>

#include "../00. includes/node/node.hpp"
#include "../00. includes/tree node/treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    void levelOrderTraversal(node<T>*);

template<typename T>
    void preorderTraversal(node<T>*);

template<typename T>
    void inorderTraversal(node<T>*);

template<typename T>
    void postorderTraversal(node<T>*);

template<typename T>
    void preOrderIterative(treeNode<T>*);

template<typename T>
    void preorderRecursive(treeNode<T>*);

template<typename T>
    void inorderRecursive(treeNode<T>*);

/* ******************************************************************************** */