/* ******************************************************************************** */

#include <iostream>
#include <cmath>

/* ******************************************************************************** */

static int gcd_mod(int u, int v){
    int t;

    u = abs(u);
    v = abs(v);

    while(u>0){
        if(u<v)
            std::swap(u, v);
        u %= v;
    }
    return v;
}

/* ******************************************************************************** */

class fraction {
    public:
        fraction(int num, int denom) : 
            numerator{num}, denominator{denom}{}
        void reduce();
        void print();
    private:
        int numerator;
        int denominator;
};

/* ******************************************************************************** */

void fraction::reduce(){
    int gcd = gcd_mod(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

void fraction::print(){
    if(numerator != 0 && denominator != 0)
        std::cout << numerator << '/' << denominator << '\n';
    else    
        throw;
}

/* ******************************************************************************** */

int main(){
    fraction f{125, 100};
    f.reduce();
    f.print();
}

/* ******************************************************************************** */