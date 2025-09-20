#pragma once

#include <iostream>

#include "../node/node.hpp"
#include "../types.hpp"

i32 massSuicideArray(i32, i32);

template<typename T>
    none massSuicideLinkedList(i32, i32);

none massSuicideRecursiveDriver(i32, i32);
i32 massSuicideRecursive(node<i32>*, i32);