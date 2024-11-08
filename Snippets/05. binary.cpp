/* ******************************************************************************** */

#include <iostream>
#include <cmath>
#include <algorithm>

/* ******************************************************************************** */

void binary(int num){
    std::string output{};
    int formatVar = 0;

    while(num>0){
        output += static_cast<char>(num%2);
        num/=2;
    }

    std::for_each(output.rbegin(), output.rend(), [&formatVar](char c){
        std::cout << static_cast<int>(c);
        formatVar++;
        if(formatVar % 4 == 0)
            std::cout << ' ';
    });

    putchar(10);
}

/* ******************************************************************************** */

int main(){
    int x = 128;
    binary(x);
}

/* ******************************************************************************** */