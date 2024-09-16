#!/bin/bash

#Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

#Build project
cmake --build build  -j 4

GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j4

./build/my_project/neetcode_linked_list_tests