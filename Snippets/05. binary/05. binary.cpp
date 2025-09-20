#include "./05. binary.hpp"

none binary(i32 num){
    std::string output{};
    i32 formatVar = 0;

    while(num>0){
        output += static_cast<i8>(num%2);
        num/=2;
    }

    std::for_each(output.rbegin(), output.rend(), [&formatVar](i8 c){
        std::cout << static_cast<i32>(c);
        formatVar++;
        if(formatVar % 4 == 0)
            std::cout << ' ';
    });

    putchar(10);
}