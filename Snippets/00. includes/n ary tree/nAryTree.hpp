/* ******************************************************************************** */

#pragram once

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
        private:
            std::vector<T> keys;

            std::vector<int> parent;
            std::vector<int> child;
            std::vector<int> sibling;

            int currentIndex;
    };

int n_ary_tree_insert_sibling_char(n_ary_tree*, int, int, char);

int n_ary_tree_level_order(n_ary_tree*);
int n_ary_tree_level_order_driver();

/* ******************************************************************************** */