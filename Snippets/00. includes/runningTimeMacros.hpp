#define runningTime(function, result) do { \
    clock_t t; \
    double sec;\
    \
    t = clock(); \
    \
    function; \
    sec = ((double)(clock() - t)) / CLOCKS_PER_SEC; \
    result = sec; \
    } \
    while(0)