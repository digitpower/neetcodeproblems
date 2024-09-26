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
        ReverseRecursively list;
        ListNode* node1 = new ListNode{1};
        ListNode* res = list.ReverseLinkedList(node1);
        ASSERT_EQ(ListToStr(res), "1");
    }
    {
        ReverseRecursively list;
        ListNode* node1 = new ListNode{1};
        ListNode* node2 = new ListNode{2};
        node1->next = node2;
        ListNode* res = list.ReverseLinkedList(node1);
        ASSERT_EQ(ListToStr(res), "2 1");
    }

    {
        ReverseRecursively list;
        ListNode* node1 = new ListNode{1};
        ListNode* node2 = new ListNode{2};
        ListNode* node3 = new ListNode{3};
        ListNode* node4 = new ListNode{4};
        ListNode* node5 = new ListNode{5};
        ListNode* node6 = new ListNode{6};
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;
        ListNode* res = list.ReverseLinkedList(node1);
        ASSERT_EQ(ListToStr(res), "6 5 4 3 2 1");
    }

}
