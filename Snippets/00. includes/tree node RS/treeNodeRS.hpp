/* ******************************************************************************** */

#pragma once

#include <iostream>

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

template<typename T>
    void insertChild(treeNodeRS<T>*, T);

template<typename T>
    void insertSibling(treeNodeRS<T>*, T);

template<typename T>
    void levelOrderTraversal(treeNodeRS<T>*);

/* ******************************************************************************** */

template<typename T>
    void visit(treeNodeRS<T>);

/* ******************************************************************************** */