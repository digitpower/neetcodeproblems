#!/bin/bash

#Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

#Build project
cmake --build build  -j 4

GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j4

./build/problems/neetcode_linked_list_tests
./build/problems/neetcode_design_browser_history_tests
./build/problems/reverse_linkedlist_recursively_tests
./build/problems/sorting_tests
./build/problems/merge_k_sorted_lists_tests
./build/problems/quick_sort_tests
./build/problems/tree_tests