cmake_minimum_required(VERSION 3.5.0)
project(sedg14 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(sedg14pp main.cpp
    "Snippets/00. includes/node/node.cpp"
    "Snippets/00. includes/tree node/treeNode.cpp"
    "Snippets/00. includes/parse tree/parseTree.cpp"
    "Snippets/00. includes/postfix/postfix.cpp"
    "Snippets/00. includes/mass suicide/massSuicide.cpp"

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

    "Snippets/13. queue/13. queueA.cpp"
    "Snippets/13. queue/13. queueL.cpp"

    "Snippets/14. 2D array/14. 2DArray.cpp"
    "Snippets/15. doubly linked list/15. doublyLinkedList.cpp"
    "Snippets/18. tree traversals/18. treeTraversals.cpp"
    "Snippets/19. fibonacci/19. fibonacci.cpp"
    "Snippets/20. ruler/20. ruler.cpp"
    "Snippets/21. fractal/21. fractal.cpp"
    "Snippets/22. recursion removal/22. recursionRemoval.cpp"
)

target_link_libraries(sedg14pp m) # Link libmath

target_compile_options(sedg14pp PRIVATE 
    -O0
    #-Wall 
    #-Werror 
    #-pedantic 
    -std=c++20
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
