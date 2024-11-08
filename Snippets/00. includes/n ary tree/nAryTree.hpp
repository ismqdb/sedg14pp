/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <queue>

template<typename T>
    class nAryTree {
        public:
            nAryTree();
            ~nAryTree();

            int insert(T);
            int insertChild(T, T);
            int insertSibling(T, T, T);
            int levelOrderTraversal();
        private:
            std::vector<T> keys;

            std::vector<int> parent;
            std::vector<int> child;
            std::vector<int> sibling;

            int currentIndex;
    };

int n_ary_tree_level_order_driver();

/* ******************************************************************************** */