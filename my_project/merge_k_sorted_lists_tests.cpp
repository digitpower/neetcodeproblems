#include <gtest/gtest.h>
#include "merge_k_sorted_lists.h"


TEST(MergeKSortedLists, MergeWithSingleEmptyList_Works)
{
    {
        std::vector<ListNode*> lists;
        ListNode* res = mergeKLists(lists, 0, lists.size());
        ASSERT_STREQ(ListToStr(res).c_str(), "");
    }
    {
        std::vector<ListNode*> lists;
        lists.push_back(nullptr);
        lists.push_back(new ListNode(1));
        ListNode* res = mergeKLists(lists, 0, lists.size());
        ASSERT_STREQ(ListToStr(res).c_str(), "1");
    }
}


TEST(MergeKSortedLists, MergeMoreThanOne_Works)
{
    std::vector<ListNode*> lists;

    ListNode* list1 = GenerateLinkedList({0,1,2,3});
    lists.push_back(list1);

    ListNode* list2 = GenerateLinkedList({4,5,6});
    lists.push_back(list2);



    ListNode* list3 = GenerateLinkedList({2,4,5,8,9,12,78});
    lists.push_back(list3);

    ListNode* res = mergeKLists(lists, 0, lists.size());
    ASSERT_STREQ(ListToStr(res).c_str(), "0 1 2 2 3 4 4 5 5 6 8 9 12 78");
}

TEST(MergeTwoSortedLists, MergeTwoSortedLists_Works)
{

    ListNode* list1 = GenerateLinkedList({0,1,2,3});
    ListNode* list2 = GenerateLinkedList({4,5,6});

    ListNode* res = mergeTwoSortedLists(list1, list2);
    ASSERT_STREQ(ListToStr(res).c_str(), "0 1 2 3 4 5 6");
}
