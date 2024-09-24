cmake_minimum_required(VERSION 3.5.0)
project(sedg14 VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(sedg14 main.c 
    "Snippets/00. includes/array/array.c"
    "Snippets/00. includes/dll node/dll_node.c"
    "Snippets/00. includes/node/node.c"
    "Snippets/00. includes/tree node/tree_node.c"

    "Snippets/01. gcd/01. gcd.c"
    "Snippets/03. fraction/03. fraction.c"
    "Snippets/04. convert/04. convert.c"
    "Snippets/05. binary/05. binary.c"
    "Snippets/06. greatest ints/06. greatest_ints.c"
    "Snippets/08. sieve/08. sieve.c"
    "Snippets/09. linked list/09. linked_list.c"
    "Snippets/09a. mass suicide/09a. mass_suicide.c"
    "Snippets/10. parallel array/10. parallel_array.c"
    "Snippets/11. stack linked list/11. stack_ll.c"
    "Snippets/11a. postfix/11a. postfix.c"
    "Snippets/12. stack array/12. stack_a.c"
    "Snippets/13. queue array/13. queue_a.c"
    "Snippets/14. 2d/14. 2d.c"
    "Snippets/15. doubly linked list/15. dl_list.c"
    "Snippets/16. stack parallel array/16. stack_pa.c"
    "Snippets/17. queue linked list/17. queue_ll.c"
    "Snippets/18. tree traversals/18. tree_traversals.c"
    "Snippets/18a. parse tree/18a. parse_tree.c"
    "Snippets/19. fibonacci/19. fibonacci.c"
    "Snippets/20. ruler/20. ruler.c"
    "Snippets/21. fractal/21. fractal.c"
    "Snippets/22. recursion removal/22. recursion_removal.c"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
