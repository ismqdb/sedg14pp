#include "./01. gcd.hpp"

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

size_t gcdMod(size_t u, size_t v){
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

size_t gcd3(size_t x, size_t y, size_t z){
    return gcdMod(gcdMod(x,y), z);
}

none driverGCD(){
    size_t x, y;
    while(std::cin >> x >> y)
        if(x>0 && y>0)
            std::cout << x << ' ' << y << ' ' << gcd(x,y) << '\n';
}