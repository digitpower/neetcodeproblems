#include <gtest/gtest.h>
#include "linkedlist.h"


namespace
{
    int GetMeaningOfLife() {return 42;}
} // namespace

TEST(TestTopic, TrivialEquality)
{
    EXPECT_EQ(GetMeaningOfLife(), 42);
}


TEST(TestTopic, CreateListCorrectly)
{
    auto* lst = new LinkedList();

    auto strOut = lst->ToStr();
    ASSERT_EQ(strOut, "") << "Empty list should print empty string!";
    
    lst->Add(1);
    strOut = lst->ToStr();
    ASSERT_EQ(strOut, "1 ") << "List contains one element problem!";


    lst->Add(2);
    lst->Add(3);
    lst->Add(4);
    lst->Add(6);
    strOut = lst->ToStr();
    ASSERT_EQ(strOut, "1 2 3 4 6 ") << "List contains more than one element display problem!";
}

TEST(TestTopic, SearchWithMoveToHead)
{
    LinkedList* lst = new LinkedList();

    bool res = true;

    //When list is empty, always return false
    res = lst->SearchWithMoveToHead(5);
    ASSERT_EQ(res, false);
    res = lst->SearchWithMoveToHead(1);
    ASSERT_EQ(res, false);



    lst->Add(1);
    lst->Add(2);
    lst->Add(3);
    lst->Add(4);
    lst->Add(6);

    res = lst->SearchWithMoveToHead(1);
    ASSERT_EQ(lst->ToStr(), "1 2 3 4 6 ");
    ASSERT_EQ(res, true);


    res = lst->SearchWithMoveToHead(5);
    ASSERT_EQ(lst->ToStr(), "1 2 3 4 6 ");
    ASSERT_EQ(res, false);


    res = lst->SearchWithMoveToHead(4);
    ASSERT_EQ(res, true);
    ASSERT_EQ(lst->ToStr(), "4 1 2 3 6 ");
}

TEST(TestTopic, RemoveDupsFromSortedLinkedList)
{
    {
        LinkedList* lst = new LinkedList();

        lst->Add(1);
        lst->Add(2);
        lst->Add(3);
        lst->Add(3);
        lst->Add(3);
        lst->Add(4);
        lst->Add(4);
        lst->Add(5);

        lst->RemoveDupFromSorted();

        ASSERT_EQ(lst->ToStr(), "1 2 3 4 5 ");    
    }

    {
        LinkedList* lst = new LinkedList();
        lst->RemoveDupFromSorted();
        ASSERT_EQ(lst->ToStr(), "");    
    }
    {
        LinkedList* lst = new LinkedList();
        lst->Add(1);
        lst->RemoveDupFromSorted();
        ASSERT_EQ(lst->ToStr(), "1 ");    
    }
    {
        LinkedList* lst = new LinkedList();
        lst->Add(1);
        lst->Add(2);
        lst->RemoveDupFromSorted();
        ASSERT_EQ(lst->ToStr(), "1 2 ");    
    }
    {
        LinkedList* lst = new LinkedList();
        lst->Add(1);
        lst->Add(1);
        lst->Add(2);
        lst->RemoveDupFromSorted();
        ASSERT_EQ(lst->ToStr(), "1 2 ");    
    }
}