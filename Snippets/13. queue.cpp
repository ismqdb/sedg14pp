/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

class queue {
    public:
        queue();
        ~queue();

        void put(int);
        int get();
        bool isEmpty();
    private:
        std::vector<int> storage;
};

/* ******************************************************************************** */

void queue::put(int v){
    storage.push_back(v);
}

int queue::get(){
    int t = storage.front();
    storage.erase(storage.begin());
    return t;
}

/* ******************************************************************************** */

queue::queue(){

}

queue::~queue(){

}

/* ******************************************************************************** */

bool queue::isEmpty(){
    return storage.empty();
}

/* ******************************************************************************** */

int main(){
    queue queue{};

    queue.put(1);
    queue.put(5);
    queue.put(10);

    while(!queue.isEmpty())
        std::cout << queue.get() << '\n';
}

/* ******************************************************************************** */