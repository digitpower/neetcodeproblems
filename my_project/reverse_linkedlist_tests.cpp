#include <gtest/gtest.h>
#include "reverse_linkedlist_recursively.h"

TEST(ReverseLinkedList, Reverse_MoreThanOneElement_Works)
{
    ReverseRecursively list;

    ListNode* node1 = new ListNode{1};
    ListNode* node2 = new ListNode{2};
    {
        ListNode* res = list.ReverseLinkedList(nullptr);
        ASSERT_EQ(ListToStr(res), "");
    }
    {
        ListNode* res = list.ReverseLinkedList(node1);
        ASSERT_EQ(ListToStr(res), "1");
    }
    {
        node1->next = node2;
        ListNode* res = list.ReverseLinkedList(node1);
        ASSERT_EQ(ListToStr(res), "2 1");
    }
}
