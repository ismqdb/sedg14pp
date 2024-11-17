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
            int insertSibling(int, int, T);
            int externalPathLength();
            void levelOrderTraversal();
        private:
            std::vector<T> keys;

            std::vector<int> parent;
            std::vector<int> child;
            std::vector<int> sibling;

            int currentIndex;
    };

/* ******************************************************************************** */

template class nAryTree<char>;

/* ******************************************************************************** */