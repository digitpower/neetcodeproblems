#include <gtest/gtest.h>
#include "mylinkedlist.h"

TEST(DesignLinkedList, AddAtHeadOnEmptyList)
{
    MyLinkedList list;
    list.addAtHead(5);

    ASSERT_EQ(ListToStr(list.m_head), "5");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "5");
}

TEST(DesignLinkedList, AddAtHeadOnEmptyListTwice)
{
    MyLinkedList list;
    list.addAtHead(5);
    list.addAtHead(10);

    ASSERT_EQ(ListToStr(list.m_head), "10 5");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "5 10");
}

TEST(DesignLinkedList, AddAtHeadOnEmptyList_10_Elements)
{
    MyLinkedList list;
    list.addAtHead(10);
    list.addAtHead(9);
    list.addAtHead(8);
    list.addAtHead(5);
    list.addAtHead(7);
    list.addAtHead(4);
    list.addAtHead(6);
    list.addAtHead(1);
    list.addAtHead(2);
    list.addAtHead(3);

    ASSERT_EQ(ListToStr(list.m_head), "3 2 1 6 4 7 5 8 9 10");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "10 9 8 5 7 4 6 1 2 3");
}

TEST(DesignLinkedList, AddAtTailOnEmptyList)
{
    MyLinkedList list;
    list.addAtTail(5);

    ASSERT_EQ(ListToStr(list.m_head), "5");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "5");
}

TEST(DesignLinkedList, AddAtTailManyElements)
{
    MyLinkedList list;
    list.addAtTail(5);
    list.addAtTail(8);
    list.addAtTail(2);

    ASSERT_EQ(ListToStr(list.m_head), "5 8 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 8 5");
}

TEST(DesignLinkedList, getWorks)
{
    {
        MyLinkedList list;
        list.addAtTail(3);
        list.addAtTail(2);
        list.addAtTail(1);

        auto res = list.get(0);
        ASSERT_EQ(res, 3);

        res = list.get(1);
        ASSERT_EQ(res, 2);

        res = list.get(2);
        ASSERT_EQ(res, 1);

        res = list.get(3);
        ASSERT_EQ(res, -1);

        res = list.get(4);
        ASSERT_EQ(res, -1);
    }
    {
        MyLinkedList list;
        auto res = list.get(0);
        ASSERT_EQ(res, -1);
        res = list.get(1);
        ASSERT_EQ(res, -1);
        res = list.get(5);
        ASSERT_EQ(res, -1);
    }
}

TEST(DesignLinkedList, addAtIndex_NotEmptyList_AtValidIndex_Works)
{
    MyLinkedList list;
    list.addAtHead(0);
    list.addAtHead(2);
    list.addAtHead(4);
    list.addAtHead(9);

    list.addAtIndex(2, 5);
    ASSERT_EQ(ListToStr(list.m_head), "9 4 5 2 0");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "0 2 5 4 9");

    //In case index is list length, we add at the end
    list.addAtIndex(5, 8);
    ASSERT_EQ(ListToStr(list.m_head), "9 4 5 2 0 8");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "8 0 2 5 4 9");
}

TEST(DesignLinkedList, AddAtIndex_NotEmptyList_AtInvalidIndex_Works)
{
    MyLinkedList list;
    //In case index is larger than list length, we do not add anything
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);

    list.addAtIndex(4, 7);
    ASSERT_EQ(ListToStr(list.m_head), "1 2 3");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "3 2 1");
}

TEST(DesignLinkedList, addAtIndex_NotEmptyList_AtNegative_Works)
{
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(2);
    list.addAtTail(4);
    list.addAtTail(9);

    list.addAtIndex(-2, 5);
    ASSERT_EQ(ListToStr(list.m_head), "0 2 4 9");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "9 4 2 0");
}

TEST(DesignLinkedList, addAtIndexZero_NonEmptyList_Works)
{
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(1);
    list.addAtTail(2);

    list.addAtIndex(0, 8);
    ASSERT_EQ(ListToStr(list.m_head), "8 0 1 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 1 0 8");
}

TEST(DesignLinkedList, addAtIndexZero_EmptyList_Works)
{
    MyLinkedList list;
    list.addAtIndex(0, 8);

    ASSERT_EQ(ListToStr(list.m_head), "8");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "8");
}

TEST(DesignLinkedList, deleteAtIndex_nonEmptyList_InTheMiddle_Works)
{
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(1);
    list.addAtTail(2);

    list.deleteAtIndex(1);
    ASSERT_EQ(ListToStr(list.m_head), "0 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 0");
}

TEST(DesignLinkedList, deleteAtIndex_MoreThanOne_deleteAtEnd_Works)
{
    //DeleteAtTail
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(1);
    list.addAtTail(2);
    list.deleteAtIndex(2);
    ASSERT_EQ(ListToStr(list.m_head), "0 1");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "1 0");
}

TEST(DesignLinkedList, deleteAtIndex_MoreThanOne_deleteAtBeginning_Works)
{
    //DeleteAtFront
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(1);
    list.addAtTail(2);
    list.deleteAtIndex(0);
    ASSERT_EQ(ListToStr(list.m_head), "1 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 1");
}


TEST(DesignLinkedList, DeleteSingleElementLinkedList_Works)
{
    //DeleteSingleElement list
    MyLinkedList list;
    list.addAtTail(0);
    list.deleteAtIndex(0);
    ASSERT_EQ(ListToStr(list.m_head), "");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "");
}

TEST(DesignLinkedList, DeleteEmptyList_Works)
{
    //Delete Empty list
    MyLinkedList list;
    list.deleteAtIndex(0);
    ASSERT_EQ(ListToStr(list.m_head), "");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "");
}

TEST(DesignLinkedList, deleteAtIndex_NoNormalIndex_Works)
{
    MyLinkedList list;
    list.addAtTail(0);
    list.addAtTail(1);
    list.addAtTail(2);

    list.deleteAtIndex(3);
    ASSERT_EQ(ListToStr(list.m_head), "0 1 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 1 0");

    list.deleteAtIndex(-1);
    ASSERT_EQ(ListToStr(list.m_head), "0 1 2");
    ASSERT_EQ(ListToStrReverse(list.m_tail), "2 1 0");
}
