#include "gtest/gtest.h"
#include "../src/linkedlist.hpp"

namespace linkedListTest
{
    TEST(LinkedListTest, PushFrontTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushFront(1);
        myList.pushFront(2);
        myList.pushFront(3);

        ASSERT_EQ(myList.size(), 3);
        ASSERT_EQ(myList.front()->val, 3);
    }

    TEST(LinkedListTest, PushEndTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);

        ASSERT_EQ(myList.size(), 3);
        ASSERT_EQ(myList.back()->val, 3);
    }

    TEST(LinkedListTest, PopFrontTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);
        myList.popFront();

        ASSERT_EQ(myList.size(), 2);
        ASSERT_EQ(myList.front()->val, 2);
    }

    TEST(LinkedListTest, PopEndTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);
        myList.popEnd();

        ASSERT_EQ(myList.size(), 2);
        ASSERT_EQ(myList.back()->val, 2);
    }

    TEST(LinkedListTest, InsertTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(4);
        myList.insert(3, 2);

        ASSERT_EQ(myList.size(), 4);
        ASSERT_EQ(myList.findAt(2)->val, 3);
    }

    TEST(LinkedListTest, EraseTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);
        myList.erase(1);

        ASSERT_EQ(myList.size(), 2);
        ASSERT_EQ(myList.front()->val, 1);
        ASSERT_EQ(myList.back()->val, 3);
    }

    TEST(LinkedListTest, FindTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);

        auto foundNode = myList.find(2);

        ASSERT_NE(foundNode, nullptr);
        ASSERT_EQ(foundNode->val, 2);
    }

    TEST(LinkedListTest, ReverseTest)
    {
        ansa::LinkedList<int> myList(nullptr);
        myList.pushEnd(1);
        myList.pushEnd(2);
        myList.pushEnd(3);
        myList.reverse();

        ASSERT_EQ(myList.size(), 3);
        ASSERT_EQ(myList.front()->val, 3);
        ASSERT_EQ(myList.back()->val, 1);
    }
}