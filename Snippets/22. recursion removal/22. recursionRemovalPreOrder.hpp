#pragma once

#include <stdio.h>
#include <stack>
#include <queue>

#include "../00. includes/types.hpp"

#include "../00. includes/tree node/treeNode.hpp"
#include "../00. includes/parse tree/parseTree.hpp"

#include "../11. stack/11. stackA.hpp"

template<typename T>
    none preOrderRR0(treeNode<T>*);

template<typename T>
    none preOrderRR1(treeNode<T>*);

template<typename T>
    none preOrderRR2(treeNode<T>*);

template<typename T>
    none preOrderRR3(treeNode<T>*);

template<typename T>
    none preOrderRR4(treeNode<T>*);

template<typename T>
    none preOrderRR4Inline(treeNode<T>*);

template<> none preOrderRR4<i8>(treeNode<i8>*);
template<> none preOrderRR4Inline<i8>(treeNode<i8>*);