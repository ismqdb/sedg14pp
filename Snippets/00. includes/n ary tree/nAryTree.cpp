/* ******************************************************************************** */

#include "./nAryTree.hpp"

/* ******************************************************************************** */

template<>
    nAryTree<char>::nAryTree(){
        this->currentIndex = 0;

        keys = std::vector<char>(100);
        child = std::vector<int>(100, -1);
        parent = std::vector<int>(100, -1);
        sibling = std::vector<int>(100, -1);
    }

template<>
    nAryTree<char>::~nAryTree(){
        this->currentIndex = 0;
    }

/* ******************************************************************************** */

template<>
    int nAryTree<char>::insert(char value){
        this->keys[this->currentIndex] = value;

        return this->currentIndex++;
    }

template<>
    int nAryTree<char>::insertChild(char parent, char child){
        this->keys[this->currentIndex] = child;

        this->parent[this->currentIndex] = parent;
        this->child[parent] = this->currentIndex;

        return this->currentIndex++;
    }

template<>
    int nAryTree<char>::insertSibling(char parent, char existingNode, char sibling){
        this->keys[this->currentIndex] = sibling;

        this->parent[existingNode] = -1;
        this->parent[this->currentIndex] = parent;

        this->sibling[existingNode] = this->currentIndex;

        return this->currentIndex++;
    }

/* ******************************************************************************** */

template<>
    void nAryTree<char>::levelOrderTraversal(){
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

template<>
    int nAryTree<char>::externalPathLength(){
        
    }

/* ******************************************************************************** */

template<>
    void nAryTree<char>::sampleData(){
        int root = this->insert('E');

        int a1 = this->insertChild(root, 'A');
        int r1 = this->insertSibling(root, a1, 'R');
        int e1 = this->insertSibling(root, r1, 'E');

        int a2 = this->insertChild(a1, 'A');
        int s1 = this->insertSibling(a1, a2, 'S');

        int t1 = this->insertChild(r1, 'T');

        int m1 = this->insertChild(t1, 'M');
        int p1 = this->insertSibling(t1, m1, 'P');
        int l1 = this->insertSibling(t1, p1, 'L');
        int e2 = this->insertSibling(t1, l1, 'E');
    }

/* ******************************************************************************** */