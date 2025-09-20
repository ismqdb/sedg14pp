#include "rand.hpp"

i32 getRand(i32 low, i32 high){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(low, high);

    return dist(rng);
}

std::vector<i32> getRandVec(i32 count, i32 low, i32 high){
    std::vector<i32> vec(count);

    for(i32 i = 0; i < count; i++)
        vec[i] = getRand(low, high);

    return vec;
}