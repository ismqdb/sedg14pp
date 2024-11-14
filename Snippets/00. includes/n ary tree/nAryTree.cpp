/* ******************************************************************************** */

#include "./nAryTree.hpp"

/* ******************************************************************************** */

template<typename T>
    nAryTree<T>::nAryTree(){
        this->currentIndex = 0;

        keys = std::vector<T>(100);
        child = std::vector<int>(100, -1);
        parent = std::vector<int>(100, -1);
        sibling = std::vector<int>(100, -1);
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
    int nAryTree<T>::insertChild(T parent, T child){
        this->keys[this->currentIndex] = child;

        this->parent[this->currentIndex] = parent;
        this->child[parent] = this->currentIndex;

        return this->currentIndex++;
    }

template<typename T>
    int nAryTree<T>::insertSibling(T parent, T existingNode, T sibling){
        this->keys[this->currentIndex] = sibling;

        this->parent[existingNode] = -1;
        this->parent[this->currentIndex] = parent;

        this->sibling[existingNode] = this->currentIndex;

        return this->currentIndex++;
    }

/* ******************************************************************************** */

template<typename T>
    void nAryTree<T>::levelOrderTraversal(){
        std::queue<int> queue{};

        int currentNode = 0;
        int currentSibling;

        queue.push(currentNode);

        while(1){
            for(
                currentSibling = this->sibling[currentNode];
                currentSibling != -1;
                currentSibling = this->sibling[currentSibling]
            )
                queue.push(currentSibling);

            while(this->child[currentNode] == -1)
                currentNode = this->sibling[currentNode];

            if(currentNode == -1)
                break;

            currentNode = this->child[currentNode];
            queue.push(currentNode);
        }

        while(!queue.empty())
            std::cout << this->keys[static_cast<int>(queue.front())];

        putchar(10);
    }

/* ******************************************************************************** */

void nAryTreeLevelOrderDriver(){
    nAryTree<char> tree{};

    int root = tree.insert('E');

    int a1 = tree.insertChild(root, 'A');
    int r1 = tree.insertSibling(root, a1, 'R');
    int e1 = tree.insertSibling(root, r1, 'E');

    int a2 = tree.insertChild(a1, 'A');
    int s1 = tree.insertSibling(a1, a2, 'S');

    int t1 = tree.insertChild(r1, 'T');

    int m1 = tree.insertChild(t1, 'M');
    int p1 = tree.insertSibling(t1, m1, 'P');
    int l1 = tree.insertSibling(t1, p1, 'L');
    int e2 = tree.insertSibling(t1, l1, 'E');

    tree.levelOrderTraversal();
}

/* ******************************************************************************** */