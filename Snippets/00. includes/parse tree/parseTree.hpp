/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include "../tree node/treeNode.hpp"

/* ******************************************************************************** */

template<typename T>
    treeNode<T>* buildParseTree();

/* ******************************************************************************** */

template<> treeNode<char>* buildParseTree();

/* ******************************************************************************** */