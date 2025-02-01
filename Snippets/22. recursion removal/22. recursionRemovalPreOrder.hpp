/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../00. includes/tree node/treeNode.hpp"
#include "../00. includes/parse tree/parseTree.hpp"

#include <stack>
#include <queue>

/* ******************************************************************************** */

template<typename T>
    void preOrderRR0(treeNode<T>*);

template<typename T>
    void preOrderRR1(treeNode<T>*);

template<typename T>
    void preOrderRR2(treeNode<T>*);

template<typename T>
    void preOrderRR3(treeNode<T>*);

template<typename T>
    void preOrderRR4(treeNode<T>*);

/* ******************************************************************************** */

template<> void preOrderRR4<char>(treeNode<char>*);

/* ******************************************************************************** */