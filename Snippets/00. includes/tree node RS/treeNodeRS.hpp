/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <queue>

/* ******************************************************************************** */

#include "../parse tree/parseTree.hpp"
#include "../types.hpp"

/* ******************************************************************************** */

template<typename T>
    struct treeNodeRS {
        T value;

        treeNodeRS<T> *child;
        treeNodeRS<T> *sibling;
        treeNodeRS<T> *parent;
    };

/* ******************************************************************************** */

template<typename T>
    treeNodeRS<T> *createNode(T);

/* ******************************************************************************** */

template<typename T>
    treeNodeRS<T>* insertChild(treeNodeRS<T>*, T);

template<typename T>
    treeNodeRS<T>* insertSibling(treeNodeRS<T>*, treeNodeRS<T>*, T);

/* ******************************************************************************** */

template<typename T>
    void levelOrderTraversal(treeNodeRS<T>*);

template<typename T>
    void externalPathLengthRS(treeNodeRS<T>*, i32, i32&);

/* ******************************************************************************** */

template<typename T>
    void visit(treeNodeRS<T>*);

/* ******************************************************************************** */