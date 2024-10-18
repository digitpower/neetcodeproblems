#pragma once
#include <vector>

#include "utils.h"

ListNode* mergeTwoSortedLists(ListNode* first, ListNode* second)
{
    ListNode* dummyNode = new ListNode(-1);
    ListNode* startNode = dummyNode;
    while(first != nullptr && second != nullptr)
    {
        if(first->val < second->val)
        {
            startNode->next = first;
            first = first->next;
        }
        else
        {
            startNode->next = second;
            second = second->next;
        }
        startNode = startNode->next;
    }
    while(first != nullptr)
    {
        startNode->next = first;
        first = first->next;
        startNode = startNode->next;
    }
    while(second != nullptr)
    {
        startNode->next = second;
        second = second->next;
        startNode = startNode->next;
    }
    return dummyNode->next;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists, int start, int length)
{
    if(length == 0 )
        return nullptr;
    if(length == 1)
        return lists[start];
    ListNode* leftList = mergeKLists(lists, start, length/2);
    ListNode* rightList = mergeKLists(lists, start + length/2, length-length/2);
    ListNode* res = mergeTwoSortedLists(leftList, rightList);
    return res;
}
