#include "./06. greatestInts.hpp"

none greatestInts(size_t& x, size_t& y){
    for(size_t i = std::numeric_limits<unsigned long long>::max(); i > 0; i--)
        for(size_t j = std::numeric_limits<unsigned long long>::max(); j > 0; j--)
            if(gcd(i,j) == 1 && i!=j){
                x = i;
                y = j;
                return;
            }
}