if(BUILD_TESTING)
    add_executable(linkedlist_tests my_test.cpp linkedlist.cpp)
    target_link_libraries(linkedlist_tests PRIVATE GTest::gtest_main)


    add_executable(neetcode_linked_list_tests neetcode_linked_list_tests.cpp )
    target_link_libraries(neetcode_linked_list_tests PRIVATE GTest::gtest_main)

    # add_executable()
    include(GoogleTest)
    gtest_discover_tests(linkedlist_tests)
    gtest_discover_tests(neetcode_linked_list_tests)
endif()