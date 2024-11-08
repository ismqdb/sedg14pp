/* ******************************************************************************** */

#pragma once

#include <iostream>

/* ******************************************************************************** */

template<typename T>
    class treeNode {
        public:
            treeNode(T value, treeNode *l, treeNode *r);
            visit();
        private:
            T info;
            treeNode* left;
            treeNode* right;
    };

/* ******************************************************************************** */