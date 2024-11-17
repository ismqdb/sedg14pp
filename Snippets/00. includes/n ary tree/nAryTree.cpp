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
    int nAryTree<T>::insertSibling(int parent, int existingNode, T sibling){
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

template<typename T>
    int nAryTree<T>::externalPathLength(){
        return 1;
    }

/* ******************************************************************************** */