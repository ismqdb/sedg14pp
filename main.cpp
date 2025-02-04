/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

#include "Snippets/00. includes/runningTimeMacros.hpp"

#include "Snippets/20. ruler/20. ruler.hpp"

/* ******************************************************************************** */

int main(){
    double x1;
    double x2;
    
    int left = 0;
    int right = pow(2, 16);
    int height = 12;

    runningTime(ruleIterative(left, right, height), x1);
    runningTime(ruleInorder(left, right, height), x2);

    std::cout << "\n\nIterative: " << x1 * 1000 << ".\n";
    std::cout << "Recursive: " << x2 * 1000 << ".\n";
}

/* ******************************************************************************** */