/* ******************************************************************************** */

#include "./10. parallelArray.hpp"

/* ******************************************************************************** */

template<typename T>
    parallelArray<T>::parallelArray(){
        int size = 50;

        key = std::vector<T>(size+2);
        next = std::vector<int>(size+2);

        head = 0;
        tail = 1;
        current = 2;

        next[head] = tail;
        next[tail] = tail;
    }

template<typename T>
    parallelArray<T>::~parallelArray(){
        
}

template<typename T>
    T& parallelArray<T>::operator[](int index){
        return this->key[index];
}

/* ******************************************************************************** */

template<typename T>
    void parallelArray<T>::deleteNext(int t){
        next[t] = next[next[t]];
    }

/* ******************************************************************************** */

template<typename T>
    char parallelArray<T>::insertAfter(T newValue, int existing){
        if(existing < 0)
            throw;

        key[current] = newValue;

        next[current] = next[existing];
        next[existing] = current;

        return current++;
    }

/* ******************************************************************************** */

template<typename T>
    bool parallelArray<T>::empty(){
        return this->current == 2;
    }

/* ******************************************************************************** */

template<typename T>
    void parallelArray<T>::printAll(){
        char x = next[head];

        while(x != next[x]){
            std::cout << key[x] << '\n';
            x = next[x];
        }

        putchar(10);
    }

/* ******************************************************************************** */

int parallelArrayDriver(){
    parallelArray<char> parray{};

    int s = parray.insertAfter('S', 0);
    int l = parray.insertAfter('L', 0);
    int a = parray.insertAfter('A', 0);

    int i = parray.insertAfter('I', l);
    int t = parray.insertAfter('T', s);

    int n = parray.insertAfter('N', a);
    int e = parray.insertAfter('E', n);
    int w = parray.insertAfter('W', e);

    int b1 = parray.insertAfter(' ', a);
    int b2 = parray.insertAfter(' ', w);

    parray.printAll();

    return 1;
}

/* ******************************************************************************** */