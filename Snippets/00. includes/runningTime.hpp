#include <chrono>

#define runningTimeNanoSeconds(function, result) do { \
    auto start = std::chrono::steady_clock::now(); \
    function; \
    auto end = std::chrono::steady_clock::now(); \
    auto diff = end - start; \
    result = std::chrono::duration<double, std::nano>(diff).count(); \
    } \
while(0)
