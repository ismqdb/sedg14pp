/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <queue>

#include "../00. includes/node/node.hpp"
#include "../00. includes/tree node/treeNode.hpp"

/* ******************************************************************************** */

void traversePreorder();

template<typename T>
    void removeRecursion1(treeNode<T>*);

template<typename T>
    void removeRecursion2(treeNode<T>*);

template<typename T>
    void removeRecursion3(treeNode<T>*);

template<typename T>
    void removeRecursion4(treeNode<T>*);

/* ******************************************************************************** */