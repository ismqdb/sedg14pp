/* ******************************************************************************** */

#include "./04. convert.hpp"

/* ******************************************************************************** */

int convert(){
    char c;
    unsigned long long value = 0;
    int pow = 1;

    std::string input{};

    while((c = std::getchar()) != EOF){
        if(!isdigit(c) || c == ' ')
            break;
        input += c;
    }

    std::for_each(input.rbegin(), input.rend(), [&pow, &value](char c){
        value += (pow * (c - '0'));
        pow *= 10;
    });

    return value;
}

/* ******************************************************************************** */