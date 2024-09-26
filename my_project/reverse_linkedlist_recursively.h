#pragma once
#include <iostream>
#include "utils.h"

class ReverseRecursively
{
    bool visitedFirstTime = true;
public:
    ListNode* ReverseLinkedList(ListNode* head)
    {
        //When there is null list initially
        if(head == nullptr)
            return head;
        
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        if(visitedFirstTime == true)
        {
            currNode->next = nullptr;
            visitedFirstTime = false;
        }
        if(nextNode == nullptr)
        {
            return currNode;
        }
        ListNode* res =  ReverseLinkedList(nextNode);
        nextNode->next = currNode;
        return res;
    }
};