#include "gtest/gtest.h"
#include "../src/vector.hpp"

namespace vectorTests
{
    TEST(AnsaVectorTest, ConstructorFromArray)
    {
        int                   arr[] = {1, 2, 3};
        ansa::AnsaVector<int> vec(arr);
        ASSERT_EQ(vec.size(), 3);
        ASSERT_EQ(vec.capacity(), 6);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 2);
        ASSERT_EQ(vec.at(2), 3);
    }

    TEST(AnsaVectorTest, PushBack)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        ASSERT_EQ(vec.size(), 3);
        ASSERT_EQ(vec.capacity(), 4);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 2);
        ASSERT_EQ(vec.at(2), 3);
    }

    TEST(AnsaVectorTest, EraseByValue)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        vec.erase(2);
        ASSERT_EQ(vec.size(), 2);
        ASSERT_EQ(vec.capacity(), 4);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 3);
    }

    TEST(AnsaVectorTest, EraseByPosition)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        vec.erase(static_cast<std::size_t>(1));
        ASSERT_EQ(vec.size(), 2);
        ASSERT_EQ(vec.capacity(), 4);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 3);
    }

    TEST(AnsaVectorTest, PopBack)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        ASSERT_EQ(vec.popBack(), 3);
        ASSERT_EQ(vec.size(), 2);
        ASSERT_EQ(vec.capacity(), 4);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 2);
    }

    TEST(AnsaVectorTest, Find)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        ASSERT_EQ(vec.find(2), 1);
        ASSERT_EQ(vec.find(4), std::numeric_limits<std::size_t>::max());
    }

    TEST(AnsaVectorTest, InsertAtIndex)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        vec.pushBack(3);
        vec.insertAtIndex(4, 1);
        ASSERT_EQ(vec.size(), 4);
        ASSERT_EQ(vec.capacity(), 4);
        ASSERT_EQ(vec.at(0), 1);
        ASSERT_EQ(vec.at(1), 4);
        ASSERT_EQ(vec.at(2), 2);
        ASSERT_EQ(vec.at(3), 3);
    }

    TEST(AnsaVectorTest, Prepend)
    {
        ansa::AnsaVector<int> vec;
        vec.prepend(1);
        vec.prepend(2);
        vec.prepend(3);
        ASSERT_EQ(vec.size(), 3);
        ASSERT_EQ(vec.capacity(), 3);
        ASSERT_EQ(vec.at(0), 3);
        ASSERT_EQ(vec.at(1), 2);
        ASSERT_EQ(vec.at(2), 1);
    }

    TEST(AnsaVectorTest, Resize)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(10);
        vec.pushBack(20);

        vec.resize(3);
        EXPECT_EQ(vec.size(), 3);
        EXPECT_EQ(vec.at(0), 10);
        EXPECT_EQ(vec.at(1), 20);
        EXPECT_EQ(vec.at(2), 0);

        vec.resize(1);
        EXPECT_EQ(vec.size(), 1);
        EXPECT_EQ(vec.at(0), 10);
    }

    TEST(AnsaVectorTest, Reserve)
    {
        ansa::AnsaVector<int> vec;
        vec.pushBack(10);
        vec.pushBack(20);

        vec.reserve(5);
        EXPECT_EQ(vec.capacity(), 5);
        EXPECT_EQ(vec.at(0), 10);
        EXPECT_EQ(vec.at(1), 20);
    }
}