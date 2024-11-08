/* ******************************************************************************** */

#include "./nAryTree.hpp"

/* ******************************************************************************** */

template<typename T>
    nAryTree<T>::nAryTree(){
        this->currentIndex = 0;
    }

template<typename T>
    nAryTree<T>::~nAryTree(){
        this->currentIndex = 0;
    }

/* ******************************************************************************** */

template<typename T>
    int nAryTree<T>::insert(T value){
        this->keys[this->currentIndex] = value;

        return this->currentIndex++;
    }

template<typename T>
    int nAryTree<T>::insert(T parent, T child){
        this->keys[this->currentIndex] = child;

        this->parent[this->currentIndex] = parent;
        this->child[parent] = this->currentIndex;

        return this->currentIndex++;
    }

template<typename T>
    int nAryTree<T>::insertSibling(T parent, T existingNode, T sibling){
        this->keys[this->currentIndex] = sibling;

        this->parent[existing_node] = -1;
        this->parent[this->currentIndex] = parent;

        this->sibling[existing_node] = this->currentIndex;

        return this->currentIndex++;
    }

/* ******************************************************************************** */

int n_ary_tree_level_order(n_ary_tree *tree){
    queue_a queue = queue_a_init(INT, 50);

    int current_node = 0;
    int current_sibling;

    queue_a_put_int(&queue, current_node);

    while(1){
        for(
            current_sibling = tree->sibling[current_node];
            current_sibling != -1;
            current_sibling = tree->sibling[current_sibling]
        )
            queue_a_put_int(&queue, current_sibling);

        while(tree->child[current_node] == -1)
            current_node = tree->sibling[current_node];

        if(current_node == -1)
            break;

        current_node = tree->child[current_node];
        queue_a_put_int(&queue, current_node);
    }

    while(!queue_a_is_empty(&queue))
        printf("%c ", (char)tree->keys.chars[queue_a_get_int(&queue)]);

    putchar(10);

    queue_a_deinit(&queue);
}

/* ******************************************************************************** */

int n_ary_tree_level_order_driver(){
    n_ary_tree tree = n_ary_tree_create(N_ARY_TREE);

    int root = n_ary_tree_insert_char(&tree, 'E');

    int a1 = n_ary_tree_insert_child_char(&tree, root, 'A');
    int r1 = n_ary_tree_insert_sibling_char(&tree, root, a1, 'R');
    int e1 = n_ary_tree_insert_sibling_char(&tree, root, r1, 'E');

    int a2 = n_ary_tree_insert_child_char(&tree, a1, 'A');
    int s1 = n_ary_tree_insert_sibling_char(&tree, a1, a2, 'S');
    int t1 = n_ary_tree_insert_sibling_char(&tree, a1, s1, 'T');

    int m1 = n_ary_tree_insert_child_char(&tree, t1, 'M');
    int p1 = n_ary_tree_insert_sibling_char(&tree, t1, m1, 'P');
    int l1 = n_ary_tree_insert_sibling_char(&tree, t1, p1, 'L');
    int e2 = n_ary_tree_insert_sibling_char(&tree, t1, l1, 'E');

    n_ary_tree_level_order(&tree);
}

/* ******************************************************************************** */