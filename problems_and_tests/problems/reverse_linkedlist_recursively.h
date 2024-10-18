#pragma once
#include <iostream>
#include "utils.h"

class ReverseRecursively
{
public:
    ListNode* ReverseLinkedList(ListNode* head)
    {
        //When there is null list initially
        if(head == nullptr)
            return head;
        
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        if(nextNode == nullptr)
            return currNode;
        ListNode* res =  ReverseLinkedList(nextNode);
        nextNode->next = currNode;
        currNode->next = nullptr;
        return res;
    }
};