/* ******************************************************************************** */

#pragma once

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

int parallelArrayDriver();

/* ******************************************************************************** */