#!/bin/bash

#Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

#Build project
cmake --build build  -j 4

GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j4

./build/my_project/neetcode_linked_list_tests
./build/my_project/neetcode_design_browser_history_tests
./build/my_project/reverse_linkedlist_recursively_tests
./build/my_project/sorting_tests
./build/my_project/merge_k_sorted_lists_tests
./build/my_project/quick_sort_tests