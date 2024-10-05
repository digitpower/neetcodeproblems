#include "utils.h"

std::string ListToStrReverse(ListNode* tail)
{
    ListNode* p = tail;
    std::ostringstream out;
    while(p != nullptr)
    {
        out << p->val;
        if(p->prev != nullptr)
            out << " ";
        p = p->prev;
    }
    return out.str();
}

std::string ListToStr(ListNode* head)
{
    ListNode* p = head;
    std::ostringstream out;
    while(p != nullptr)
    {
        out << p->val;
        if(p->next != nullptr)
            out << " ";
        p = p->next;
    }
    return out.str();
}

std::string ArrayRepr(int (&arr)[], int sz, int startIndex)
{
    std::ostringstream out;
    for (size_t i = startIndex; i < sz; i++)
    {
        out << arr[i];
        if(i < sz - 1)
            out << " ";
    }
    return out.str();
}

ListNode* GenerateLinkedList(const std::vector<int>& numbers)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* start = dummy;
    for (auto number : numbers)
    {
        start->next = new ListNode(number);
        start = start->next;
    }
    return dummy->next;
}