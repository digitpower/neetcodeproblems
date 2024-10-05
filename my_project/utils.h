#pragma once
#include <string>
#include <sstream>
#include <vector>

struct ListNode {
    ListNode(int _val) : 
        val(_val) {}
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    int val;
};

std::string ListToStrReverse(ListNode* tail);

std::string ListToStr(ListNode* head);

std::string ArrayRepr(int (&arr)[], int sz, int startIndex = 0);

ListNode* GenerateLinkedList(const std::vector<int>& numbers);