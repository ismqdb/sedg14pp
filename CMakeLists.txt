cmake_minimum_required(VERSION 3.10.0)
project(sedg14 VERSION 0.1.0 LANGUAGES C CXX)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("sedg14pp")

add_executable(sedg14pp main.cpp
    "Snippets/00. includes/node/node.cpp"
    "Snippets/00. includes/tree node/treeNode.cpp"
    "Snippets/00. includes/parse tree/parseTree.cpp"
    "Snippets/00. includes/postfix/postfix.cpp"
    "Snippets/00. includes/mass suicide/massSuicide.cpp"
    "Snippets/00. includes/point/point.cpp"
    #"Snippets/00. includes/result/result.cpp"
    "Snippets/00. includes/rand/rand.cpp"

    "Snippets/00. includes/recurrences/halfInput.cpp"
    "Snippets/00. includes/recurrences/largestLog.cpp"

    "Snippets/01. gcd/01. gcd.cpp"
    "Snippets/03. fraction/03. fraction.cpp"
    "Snippets/04. convert/04. convert.cpp"
    "Snippets/05. binary/05. binary.cpp"
    "Snippets/06. greatest ints/06. greatestInts.cpp"
    "Snippets/08. sieve/08. sieve.cpp"
    "Snippets/09. linked list/09. linkedList.cpp"
    "Snippets/09. linked list/09. linkedListGT.cpp"
    "Snippets/10. parallel array/10. parallelArray.cpp"

    "Snippets/11. stack/11. stackL.cpp"
    "Snippets/11. stack/11. stackA.cpp"
    "Snippets/11. stack/11. stackPA.cpp"
    "Snippets/11. stack/11. stackLF.cpp"

    "Snippets/13. queue/13. queueA.cpp"
    "Snippets/13. queue/13. queueL.cpp"

    "Snippets/14. 2D array/14. 2DArray.cpp"
    "Snippets/15. doubly linked list/15. doublyLinkedList.cpp"
    "Snippets/18. tree traversals/18. treeTraversals.cpp"
    "Snippets/19. fibonacci/19. fibonacci.cpp"
    "Snippets/20. ruler/20. ruler.cpp"
    "Snippets/21. fractal/21. fractal.cpp"

    "Snippets/22. recursion removal/22. recursionRemovalPreOrder.cpp"
    "Snippets/22. recursion removal/22. recursionRemovalInOrder.cpp"
    "Snippets/22. recursion removal/22. recursionRemovalPostOrder.cpp"

    "Snippets/23. sort/23. sort.cpp"
    "Snippets/23. sort/23. sort3.cpp"
    "Snippets/23. sort/23. sort4.cpp"
    "Snippets/23. sort/23. insSort.cpp"
    "Snippets/23. sort/23. dcount.cpp"
    "Snippets/23. sort/23. shellSort.cpp"
    "Snippets/23. sort/23. qsort.cpp"
)

#target_link_libraries(sedg14pp m) # Link libmath

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sedg14pp PROPERTY CXX_STANDARD 20)
endif()
