#include <string>
#include <sstream>

struct ListNode {
    ListNode(int _val) : val(_val) {}
    ListNode* next;
    ListNode* prev;
    int val;
};

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

std::string ArrayRepr(int (&arr)[], int sz)
{
    std::ostringstream out;
    for (size_t i = 0; i < sz; i++)
    {
        out << arr[i];
        if(i < sz - 1)
            out << " ";
    }
    return out.str();
}