/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "../types.hpp"

/* ******************************************************************************** */

std::string getPostfix();

template<typename Type, typename Func>
    Type calculate(Type, Type, Func);

bool isOperator(i8);
int evaluate(std::string&);
void postfixDriver();

/* ******************************************************************************** */