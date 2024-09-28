#pragma once

void merge_intervals(int (&array)[], size_t leftStart, size_t leftSize, size_t rightStart, size_t rightSize, int (&tmpArr)[])
{
    int start = leftStart;
    int nextToLeftEnd = leftStart + leftSize;
    int nextToRightEnd = rightStart + rightSize;

    int finalStart = leftStart;
    int finalLength = leftSize + rightSize;

    while (leftStart < nextToLeftEnd && rightStart < nextToRightEnd)
    {
        if(array[leftStart] < array[rightStart])
        {
            tmpArr[start] = array[leftStart];
            leftStart++;
            start++;
        }
        else
        {
            tmpArr[start] = array[rightStart];
            rightStart++;
            start++;
        }
    }
    while (leftStart < nextToLeftEnd)
    {
        tmpArr[start] = array[leftStart];
        start++;
        leftStart++;
    }
    while (rightStart < nextToRightEnd)
    {
        tmpArr[start] = array[rightStart];
        start++;
        rightStart++;
    }

    for (size_t i = finalStart; i < finalStart + finalLength; i++)
        array[i] = tmpArr[i];
    
}

void merge_sort(int (&array)[], int start, int sz, int (&tmpArray)[])
{
    if(
        sz == 0 //case for initial empty array 
    || sz == 1)
        return;
    //sz = 7  0 3
    merge_sort(array, start, sz/2, tmpArray);
    auto leftStart = start;
    auto leftSize = sz/2;
    merge_sort(array, start + sz/2, sz - sz/2, tmpArray);
    auto rightStart = start + sz/2;
    auto rightSize = sz - sz/2;
    merge_intervals(array, leftStart, leftSize, rightStart, rightSize, tmpArray);
}
