/* ******************************************************************************** */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

/* ******************************************************************************** */

size_t gcd(size_t u, size_t v){
    size_t t;

    u = abs(u);
    v = abs(v);

    while(u > 0){
        if(u < v)
            std::swap(u, v);
        u = u-v;
    }
    return v;
}

/* ******************************************************************************** */

void greatestInts(size_t& x, size_t& y){
    for(size_t i = std::numeric_limits<unsigned long long>::max(); i > 0; i--)
        for(size_t j = std::numeric_limits<unsigned long long>::max(); j > 0; j--)
            if(gcd(i,j) == 1 && i!=j){
                x = i;
                y = j;
                return;
            }
}

/* ******************************************************************************** */

int main(){
    size_t x, y;
    greatestInts(x, y);
    std::cout << x << ' ' << y << '\n';
}

/* ******************************************************************************** */