#pragma once

#include <iostream>

#include "../00. includes/types.hpp"

none mark(i32, i32);

/*
* Height of a individual mark of a ruler.
* Implemented as a number of trailing zeroes of a number.
*/
i32 rulerMarkHeight(i32);

none ruleLevelOrder(i32, i32, i32);
none rulePreorder(i32, i32, i32);
none ruleInorder(i32, i32, i32);

none ruleIterative(i32, i32, i32);