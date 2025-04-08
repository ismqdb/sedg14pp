/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include "../tree node/treeNode.hpp"
#include "../types.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree();

/* ******************************************************************************** */

template<> treeNode<i8>* buildParseTree();

/* ******************************************************************************** */