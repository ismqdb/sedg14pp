/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/* ******************************************************************************** */

std::string getPostfix();

template<typename Type, typename Func>
    Type calculate(Type, Type, Func);

bool isOperator(char);
int evaluate(std::string&);
void postfixDriver();

/* ******************************************************************************** */