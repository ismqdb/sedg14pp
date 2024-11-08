/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

class parallelArray {
    public:
        parallelArray(int);
        ~parallelArray();

        void deleteNext(char);
        char insertAfter(char, char);
        void printAll();
    private:
        std::vector<char> key;
        std::vector<char> next;
        char current;
        char head;
        char tail;
};

/* ******************************************************************************** */

parallelArray::parallelArray(int size){
    key = std::vector<char>(size+2);
    next = std::vector<char>(size+2);

    head = 0;
    tail = 1;
    current = 2;

    next[head] = tail;
    next[tail] = tail;
}

parallelArray::~parallelArray(){
    
}

/* ******************************************************************************** */

void parallelArray::deleteNext(char t){
    next[t] = next[next[t]];
}

/* ******************************************************************************** */

char parallelArray::insertAfter(char newValue, char existing){
    if(existing < 0)
        throw;

    key[current] = newValue;

    next[current] = next[existing];
    next[existing] = current;

    return current++;
}

/* ******************************************************************************** */

void parallelArray::printAll(){
    char x = next[head];

    while(x != next[x]){
        std::cout << key[x] << '\n';
        x = next[x];
    }

    putchar(10);
}

/* ******************************************************************************** */

int main(){
    parallelArray parray(10);

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
}

/* ******************************************************************************** */