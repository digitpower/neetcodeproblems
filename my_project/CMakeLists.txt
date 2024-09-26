if(BUILD_TESTING)

    add_executable(neetcode_linked_list_tests neetcode_linked_list_tests.cpp )
    target_link_libraries(neetcode_linked_list_tests PRIVATE GTest::gtest_main)

    add_executable(neetcode_design_browser_history_tests neetcode_design_browser_history_tests.cpp )
    target_link_libraries(neetcode_design_browser_history_tests PRIVATE GTest::gtest_main)


    add_executable(reverse_linkedlist_recursively_tests reverse_linkedlist_tests.cpp )
    target_link_libraries(reverse_linkedlist_recursively_tests PRIVATE GTest::gtest_main)

    # add_executable()
    include(GoogleTest)
    #gtest_discover_tests(neetcode_linked_list_tests)
    gtest_discover_tests(reverse_linkedlist_recursively_tests)
endif()