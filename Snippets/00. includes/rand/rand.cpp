/* ******************************************************************************** */

#include "rand.hpp"

/* ******************************************************************************** */

int getRand(int low, int high){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(low, high);

    return dist(rng);
}

/* ******************************************************************************** */

std::vector<int> getRandVec(int count, int low, int high){
    std::vector<int> vec(count);

    for(int i = 0; i < count; i++)
        vec[i] = getRand(low, high);

    return vec;
}

/* ******************************************************************************** */