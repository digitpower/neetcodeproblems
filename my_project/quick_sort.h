#pragma once

int quickSortPartition(int (&arr)[], int sz)
{
    int i = 1;
    int j = sz - 1;
    int pivotIndex = 0;

    while(i <= j)
    {
        while(arr[i] <= arr[pivotIndex] && i < sz)
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

void quickSort(int (&arr)[], int sz)
{
}