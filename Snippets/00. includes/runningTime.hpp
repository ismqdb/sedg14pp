#include <chrono>

#define runningTimeMilliSeconds(function, result) do { \
    auto start = std::chrono::steady_clock::now(); \
    function; \
    auto end = std::chrono::steady_clock::now(); \
    auto diff = end - start; \
    result = std::chrono::duration<double, std::milli>(diff).count(); \
    } \
while(0)
