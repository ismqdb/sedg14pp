#include "./04. convert.hpp"

i32 convert(){
    i8 c;
    size_t value = 0;
    i32 pow = 1;

    std::string input{};

    while((c = std::getchar()) != EOF){
        if(!isdigit(c) || c == ' ')
            break;
        input += c;
    }

    std::for_each(input.rbegin(), input.rend(), [&pow, &value](u8 c){
        value += (pow * (c - '0'));
        pow *= 10;
    });

    return value;
}