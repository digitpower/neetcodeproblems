#include <gtest/gtest.h>
#include "mylinkedlist.h"

TEST(DesignLinkedList, AddAtHeadOnEmptyList)
{
    MyLinkedList list;
    list.addAtHead(5);

    ASSERT_EQ(list.ToStr(), "5");
}

TEST(DesignLinkedList, AddAtHeadOnEmptyListTwice)
{
    MyLinkedList list;
    list.addAtHead(5);
    list.addAtHead(10);

    ASSERT_EQ(list.ToStr(), "10 5");
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
}

TEST(DesignLinkedList, AddAtTailOnEmptyList)
{
    MyLinkedList list;
    list.addAtTail(5);

    ASSERT_EQ(list.ToStr(), "5");
}