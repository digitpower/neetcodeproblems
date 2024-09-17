#include <gtest/gtest.h>
#include "mylinkedlist.h"

TEST(DesignLinkedList, AddAtHeadOnEmptyList)
{
    MyLinkedList list;
    list.addAtHead(5);

    ASSERT_EQ(list.ToStr(), "5");
    ASSERT_EQ(list.ToStrReverse(), "5");
}

TEST(DesignLinkedList, AddAtHeadOnEmptyListTwice)
{
    MyLinkedList list;
    list.addAtHead(5);
    list.addAtHead(10);

    ASSERT_EQ(list.ToStr(), "10 5");
    ASSERT_EQ(list.ToStrReverse(), "5 10");
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

    ASSERT_EQ(list.ToStr(), "3 2 1 6 4 7 5 8 9 10");
    ASSERT_EQ(list.ToStrReverse(), "10 9 8 5 7 4 6 1 2 3");
}

TEST(DesignLinkedList, AddAtTailOnEmptyList)
{
    MyLinkedList list;
    list.addAtTail(5);

    ASSERT_EQ(list.ToStr(), "5");
    ASSERT_EQ(list.ToStrReverse(), "5");
}

TEST(DesignLinkedList, AddAtTailManyElements)
{
    MyLinkedList list;
    list.addAtTail(5);
    list.addAtTail(8);
    list.addAtTail(2);

    ASSERT_EQ(list.ToStr(), "5 8 2");
    ASSERT_EQ(list.ToStrReverse(), "2 8 5");
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