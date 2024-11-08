/* ******************************************************************************** */

#include <iostream>
#include <cmath>

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

size_t gcd_mod(size_t u, size_t v){
    size_t t;

    while(u>0){
        if(u<v)
            std::swap(u, v);
        std::cout << u << v << '\n';
        u %= v;
    }
    std::cout << u << v << '\n';
    return v;
}

size_t gcd_3(size_t x, size_t y, size_t z){
    return gcd_mod(gcd_mod(x,y), z);
}

/* ******************************************************************************** */

void driver_gcd(){
    size_t x, y;
    while(std::cin >> x >> y)
        if(x>0 && y>0)
            std::cout << x << ' ' << y << ' ' << gcd(x,y) << '\n';
}

/* ******************************************************************************** */

int main(){
    driver_gcd();
}