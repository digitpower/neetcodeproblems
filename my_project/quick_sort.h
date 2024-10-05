#pragma once

#include "utils.h"
int quickSortPartition(int (&arr)[], int start, int sz)
{
    if(sz == 1)
        return start;
    int i = start + 1;
    int j = start + sz - 1;
    int pivotIndex = start;

    while(i <= j)
    {
        while(arr[i] <= arr[pivotIndex] && i < i+ sz)
            i++;
        while(arr[j] > arr[pivotIndex])
            j--;
        if(i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[j];
    arr[j] = arr[pivotIndex];
    arr[pivotIndex] = tmp;
    return j;
}

void quickSort(int (&arr)[], int start, int sz)
{
    if(sz == 0 || sz == 1)
        return;
    int pIndex = quickSortPartition(arr, start, sz);
    if(start < pIndex)
    {
        int size = pIndex - start;
        quickSort(arr, start, size);
    }
    if(pIndex < start + sz - 1)
    {
        int lastElementIndex = start + sz - 1;
        int startIndex = pIndex + 1;
        int size = lastElementIndex - pIndex;
        quickSort(arr, startIndex, size);
    }
}