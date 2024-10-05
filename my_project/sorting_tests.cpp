#include <gtest/gtest.h>
#include "utils.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"


TEST(SortingSuite, InsertionSort_Works)
{
    {
        int arr[0];
        insertion_sort(arr, 0);

        auto res = ArrayRepr(arr, 0);
        ASSERT_STREQ(res.c_str(), "");
    }
    {
        const int sz = 1;
        int arr[sz];
        arr[0] = 7;
        insertion_sort(arr, sz);

        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "7");
    }
    {
        const int sz = 20;
        int arr[]{19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
        insertion_sort(arr, sz);
        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19");
    }
    {
        const int sz = 20;
        int arr[]{2,17,17,3,5,9,9,4,7,17,14,18,14,9,17,14,13,14,3,12};
        insertion_sort(arr, sz);
        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "2 3 3 4 5 7 9 9 9 12 13 14 14 14 14 17 17 17 17 18");
    }
}


TEST(SortingSuite, MergeSort_Works)
{
    {
        const int sz = 0;
        int arr[sz];
        int tmp_arr[sz];
        merge_sort(arr, 0, 0, tmp_arr);

        auto res = ArrayRepr(arr, 0);
        ASSERT_STREQ(res.c_str(), "");
    }
    {
        const int sz = 1;
        int arr[sz];
        arr[0] = 7;
        int tmp_arr[sz];
        merge_sort(arr, 0, sz, tmp_arr);

        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "7");
    }
    {
        const int sz = 3;
        int arr[]{2,1,0};
        int tmp_arr[sz];
        merge_sort(arr, 0, sz, tmp_arr);
        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "0 1 2");
    }
    {
        const int sz = 20;
        int arr[]{2,17,17,3,5,9,9,4,7,17,14,18,14,9,17,14,13,14,3,12};
        int tmp_arr[sz];
        merge_sort(arr, 0, sz, tmp_arr);
        auto res = ArrayRepr(arr, sz);
        ASSERT_STREQ(res.c_str(), "2 3 3 4 5 7 9 9 9 12 13 14 14 14 14 17 17 17 17 18");
    }
}
