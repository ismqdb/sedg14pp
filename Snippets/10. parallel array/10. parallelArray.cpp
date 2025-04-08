/* ******************************************************************************** */

#include "./10. parallelArray.hpp"

/* ******************************************************************************** */

template<typename T>
    parallelArray<T>::parallelArray(){
        i32 size = 50;

        key = std::vector<T>(size+2);
        next = std::vector<i32>(size+2);

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
    T& parallelArray<T>::operator[](i32 index){
        return this->key[index];
}

/* ******************************************************************************** */

template<typename T>
    void parallelArray<T>::deleteNext(i32 t){
        next[t] = next[next[t]];
    }

/* ******************************************************************************** */

template<typename T>
    i8 parallelArray<T>::insertAfter(T newValue, i32 existing){
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
        i8 x = next[head];

        while(x != next[x]){
            std::cout << key[x] << '\n';
            x = next[x];
        }

        putchar(10);
    }

/* ******************************************************************************** */

i32 parallelArrayDriver(){
    parallelArray<i8> parray{};

    i32 s = parray.insertAfter('S', 0);
    i32 l = parray.insertAfter('L', 0);
    i32 a = parray.insertAfter('A', 0);

    i32 i = parray.insertAfter('I', l);
    i32 t = parray.insertAfter('T', s);

    i32 n = parray.insertAfter('N', a);
    i32 e = parray.insertAfter('E', n);
    i32 w = parray.insertAfter('W', e);

    i32 b1 = parray.insertAfter(' ', a);
    i32 b2 = parray.insertAfter(' ', w);

    parray.printAll();

    return 1;
}

/* ******************************************************************************** */