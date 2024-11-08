/* ******************************************************************************** */

#pragma once

#include <iostream>

/* ******************************************************************************** */

template<typename T>
    class treeNode {
        public:
            treeNode(T value, treeNode *l, treeNode *r);
            void visit();
        private:
            int info;
            treeNode* left;
            treeNode* right;
    };

/* ******************************************************************************** */