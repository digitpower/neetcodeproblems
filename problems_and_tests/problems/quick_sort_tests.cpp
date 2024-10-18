#include <gtest/gtest.h>
#include "quick_sort.h"
#include "utils.h"

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

TEST(QuickSortingSuite, QuickSort_Partitioning_Works)
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
    newPivotIndex = quickSortPartition(arr1, 0, 5);
    ASSERT_EQ(newPivotIndex, 2);
    isCorrect = IsPartitioningCorrect(arr1, 0, 5, 2);
    ASSERT_TRUE(isCorrect);

    newPivotIndex = quickSortPartition(arr2, 0, 5);
    ASSERT_EQ(newPivotIndex, 0);
    isCorrect = IsPartitioningCorrect(arr2, 0, 5, 0);
    ASSERT_TRUE(isCorrect);

    newPivotIndex = quickSortPartition(arr3, 0, 5);
    ASSERT_EQ(newPivotIndex, 4);
    isCorrect = IsPartitioningCorrect(arr3, 0, 5, 4);
    ASSERT_TRUE(isCorrect);




    newPivotIndex = quickSortPartition(arr4, 0, 4);
    ASSERT_EQ(newPivotIndex, 3);
    isCorrect = IsPartitioningCorrect(arr4, 0, 4, 3);
    ASSERT_TRUE(isCorrect);

    //TODO How to work to this kind of data?
    // newPivotIndex = quickSortPartition(arr5, 7);
    // ASSERT_EQ(newPivotIndex, 7);
    // isCorrect = IsPartitioningCorrect(arr5, 0, 7, 7);
    // ASSERT_TRUE(isCorrect);


    newPivotIndex = quickSortPartition(arr6, 0, 2);
    ASSERT_EQ(newPivotIndex, 0);
    isCorrect = IsPartitioningCorrect(arr6, 0, 2, 0);
    ASSERT_TRUE(isCorrect);

    newPivotIndex = quickSortPartition(arr7, 0, 2);
    ASSERT_EQ(newPivotIndex, 1);
    isCorrect = IsPartitioningCorrect(arr7, 0, 2, 1);
    ASSERT_TRUE(isCorrect);
}

TEST(QuickSortingSuite, QuickSort_Works_1)
{
    const int sz = 0;
    int arr[sz];
    quickSort(arr, 0, 0);
    auto res = ArrayRepr(arr, 0);
    ASSERT_STREQ(res.c_str(), "");
}
TEST(QuickSortingSuite, QuickSort_Works_2)
{
    const int sz = 1;
    int arr[sz];
    arr[0] = 7;
    quickSort(arr, 0, sz);
    auto res = ArrayRepr(arr, sz);
    ASSERT_STREQ(res.c_str(), "7");
}
TEST(QuickSortingSuite, QuickSort_Works_3)
{
    const int sz = 5;
    int arr[]{1, 2, 3, 4, 5};
    quickSort(arr, 0, sz);
    auto res = ArrayRepr(arr, sz);
    ASSERT_STREQ(res.c_str(), "1 2 3 4 5");
}
TEST(QuickSortingSuite, QuickSort_Works_4)
{
    const int sz = 5;
    int arr[]{5, 4, 3, 2, 1};
    quickSort(arr, 0, sz);
    auto res = ArrayRepr(arr, sz);
    ASSERT_STREQ(res.c_str(), "1 2 3 4 5");
}
TEST(QuickSortingSuite, QuickSort_Works_5)
{
    const int sz = 9;
    int arr[]{3, 7, 8, 5, 2, 1, 9, 4, 6};
    quickSort(arr, 0, sz);
    auto res = ArrayRepr(arr, sz);
    ASSERT_STREQ(res.c_str(), "1 2 3 4 5 6 7 8 9");
}
TEST(QuickSortingSuite, QuickSort_Works_6)
{
    const int sz = 11;
    int arr[]{3, 7, 8, 5, 2, 1, 9, 4, 6, 3, 7};
    quickSort(arr, 0, sz);
    auto res = ArrayRepr(arr, sz);
    ASSERT_STREQ(res.c_str(), "1 2 3 3 4 5 6 7 7 8 9");
}
