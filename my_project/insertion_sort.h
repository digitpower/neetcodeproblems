#pragma once


//Lets we have cards in our hand
void insertion_sort(int (&array)[], int sz)
{
    for (size_t i = 1; i < sz; i++)
    {
        size_t j = i;
        //Let's we want to place specific card to proper place.
        //Move this card to it's place by exchanging it to
        //previous cards step-by-step
        while (j >= 1 && array[j-1] > array[j])
        {
            int tmp = array[j];
            array[j] = array[j-1];
            array[j-1] = tmp;
            j--;
        }
    }
}