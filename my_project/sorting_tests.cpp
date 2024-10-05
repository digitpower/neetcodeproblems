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



bool IsPartitioningCorrect(int (&arr)[], int low, int high, int pivot_index)
{
    auto pivot = arr[pivot_index];
    for (int i = 0; i <= pivot_index; i++)
        if (arr[i] > pivot)
            return false;
    for (int i = pivot_index + 1; i < high; i++)
        if (arr[i] < pivot)
            return false;
    return true;
}


TEST(SortingSuite, QuickSort_Partitioning_Works)
{
        
        int arr1[]{3, 2, 1, 5, 4};   // Random elements
        int arr2[]{1, 2, 3, 4, 5};   // Already sorted
        int arr3[]{5, 4, 3, 2, 1};   // Reverse sorted
        int arr4[]{3, 3, 3, 3};      //All elements equal
        int arr5[]{4, 2, 4, 4, 6, 4, 8};  //With duplicates
        int arr6[]{1,2};
        int arr7[]{2,1};


        int newPivotIndex = -1;

        bool isCorrect = false;
        newPivotIndex = quickSortPartition(arr1, 5);
        ASSERT_EQ(newPivotIndex, 2);
        isCorrect = IsPartitioningCorrect(arr1, 0, 5, 2);
        ASSERT_TRUE(isCorrect);

        newPivotIndex = quickSortPartition(arr2, 5);
        ASSERT_EQ(newPivotIndex, 0);
        isCorrect = IsPartitioningCorrect(arr2, 0, 5, 0);
        ASSERT_TRUE(isCorrect);

        newPivotIndex = quickSortPartition(arr3, 5);
        ASSERT_EQ(newPivotIndex, 4);
        isCorrect = IsPartitioningCorrect(arr3, 0, 5, 4);
        ASSERT_TRUE(isCorrect);







        newPivotIndex = quickSortPartition(arr4, 4);
        ASSERT_EQ(newPivotIndex, 3);
        isCorrect = IsPartitioningCorrect(arr4, 0, 4, 3);
        ASSERT_TRUE(isCorrect);

        //TODO How to work to this kind of data?
        // newPivotIndex = quickSortPartition(arr5, 7);
        // ASSERT_EQ(newPivotIndex, 7);
        // isCorrect = IsPartitioningCorrect(arr5, 0, 7, 7);
        // ASSERT_TRUE(isCorrect);


        newPivotIndex = quickSortPartition(arr6, 2);
        ASSERT_EQ(newPivotIndex, 0);
        isCorrect = IsPartitioningCorrect(arr6, 0, 2, 0);
        ASSERT_TRUE(isCorrect);

        newPivotIndex = quickSortPartition(arr7, 2);
        ASSERT_EQ(newPivotIndex, 1);
        isCorrect = IsPartitioningCorrect(arr7, 0, 2, 1);
        ASSERT_TRUE(isCorrect);
}

TEST(SortingSuite, QuickSort_Works)
{

}