cmake_minimum_required(VERSION 3.8.0)

project(cracking_coding_interview VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

include_directories("include")

# TODO: Add clang support
add_compile_options(-Wall -Wextra)

add_subdirectory(src/01_arrays_strings/)
add_subdirectory(src/02_linked_list/)
add_subdirectory(src/04_trees_graphs/)
add_subdirectory(src/05_bits/)
add_subdirectory(src/08_recursion_dynamic/)
add_subdirectory(src/10_sort_search/)

set(TEST_SOURCES)
include(test/add_test_sources.cmake)

add_executable(cracking_coding_interview ${TEST_SOURCES})
target_link_libraries(cracking_coding_interview
    ${GTEST_BOTH_LIBRARIES}
    pthread
    chapter_1
    chapter_2
    chapter_4
    chapter_5
    chapter_8
    chapter_10
)

