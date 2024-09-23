cmake_minimum_required(VERSION 3.5.0)
project(sedg14 VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(sedg14 main.c 
    "Snippets/00. Includes/array/array.c"
    "Snippets/00. Includes/dll node/dll_node.c"
    "Snippets/00. Includes/node/node.c"
    "Snippets/00. Includes/node f/node_f.c"
    "Snippets/00. Includes/tree node/tree_node.c"

    "Snippets/12. stack array/12. stack_a.c"
    "Snippets/13. queue array/13. queue_a.c"
    "Snippets/18a. parse tree/18a. parse_tree.c"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
