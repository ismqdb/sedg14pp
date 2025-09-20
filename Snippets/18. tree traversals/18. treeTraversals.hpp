#pragma once

#include <iostream>
#include <stack>
#include <queue>

#include "../00. includes/types.hpp"

#include "../00. includes/tree node/treeNode.hpp"

template<typename T>
    none levelOrderTraversal(treeNode<T>*);

template<typename T>
    none preorderTraversal(treeNode<T>*);

template<typename T>
    none inorderTraversal(treeNode<T>*);

template<typename T>
    none postorderTraversal(treeNode<T>*);

template<typename T>
    none preorderIterative(treeNode<T>*);

template<typename T>
    none preorderRecursive(treeNode<T>*);

template<typename T>
    none inorderRecursive(treeNode<T>*);

template<> none preorderTraversal<i8>(treeNode<i8>*);
template<> none preorderIterative<i8>(treeNode<i8>*);
template<> none preorderRecursive<i8>(treeNode<i8>*);