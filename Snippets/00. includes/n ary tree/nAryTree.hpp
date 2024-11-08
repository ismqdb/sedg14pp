/* ******************************************************************************** */

#pragram once

#include <iostream>
#include <queue>

template<typename T>
    class nAryTree {
        public:
            nAryTree();
            ~nAryTree();
        private:
            std::vector<T> keys;

            std::vector<int> parent;
            std::vector<int> child;
            std::vector<int> sibling;

            int current_index;
            int current_size;
            int allocated_size;
            int block_size;
    };

int n_ary_tree_insert_char(n_ary_tree*, char);
int n_ary_tree_insert_child_char(n_ary_tree*, int, char);
int n_ary_tree_insert_sibling_char(n_ary_tree*, int, int, char);

int n_ary_tree_level_order(n_ary_tree*);
int n_ary_tree_level_order_driver();

/* ******************************************************************************** */