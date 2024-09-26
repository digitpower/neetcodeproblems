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
        {
            return currNode;
        }
        std::cout << currNode->val << " : " << nextNode->val << std::endl;
        ListNode* res =  ReverseLinkedList(nextNode);
        nextNode->next = currNode;
        return res;
        // std::cout << ";" << head->val << std::endl;
    }
};