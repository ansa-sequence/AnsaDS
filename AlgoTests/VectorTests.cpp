#include "gtest/gtest.h"
#include "../src/vector.hpp"

namespace vectorTests
{
	TEST(AnsaVectorTest, ConstructorTest)
	{
		int                   arr[5] = {1, 2, 3, 4, 5};
		ansa::AnsaVector<int> vec(arr);
		ASSERT_EQ(vec.size(), 5);
		ASSERT_EQ(vec.capacity(), 10);
		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			ASSERT_EQ(vec.at(i), arr[i]);
		}
	}

	TEST(AnsaVectorTest, PushBackTest)
	{
		ansa::AnsaVector<int> vec;
		ASSERT_EQ(vec.size(), 0);
		ASSERT_EQ(vec.capacity(), 0);

		vec.pushBack(1);
		ASSERT_EQ(vec.size(), 1);
		ASSERT_EQ(vec.capacity(), 2);
		ASSERT_EQ(vec.at(0), 1);

		vec.pushBack(2);
		ASSERT_EQ(vec.size(), 2);
		ASSERT_EQ(vec.capacity(), 2);
		ASSERT_EQ(vec.at(0), 1);
		ASSERT_EQ(vec.at(1), 2);

		vec.pushBack(3);
		vec.pushBack(4);
		vec.pushBack(5);
		vec.pushBack(6);
		vec.pushBack(7);
		vec.pushBack(8);
		vec.pushBack(9);
		vec.pushBack(10);
		ASSERT_EQ(vec.size(), 10);
		ASSERT_EQ(vec.capacity(), 16);
		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			ASSERT_EQ(vec.at(i), i + 1);
		}
	}

	TEST(VectorTest, PopBack_EmptyVector)
	{
		ansa::AnsaVector<int> vec;
		EXPECT_THROW(vec.popBack(), std::out_of_range);
	}

	TEST(VectorTest, PopBack_SingleElement)
	{
		ansa::AnsaVector<int> vec;
		vec.pushBack(42);
		EXPECT_EQ(42, vec.popBack());
		EXPECT_EQ(0, vec.size());
	}

	TEST(VectorTest, PopBack_MultipleElements)
	{
		ansa::AnsaVector<int> vec;
		vec.pushBack(1);
		vec.pushBack(2);
		vec.pushBack(3);
		EXPECT_EQ(3, vec.popBack());
		EXPECT_EQ(2, vec.size());
		EXPECT_EQ(2, vec.popBack());
		EXPECT_EQ(1, vec.size());
		EXPECT_EQ(1, vec.popBack());
		EXPECT_EQ(0, vec.size());
	}

	TEST(VectorTest, PopBack_ModifyElements)
	{
		ansa::AnsaVector<int> vec;
		vec.pushBack(1);
		vec.pushBack(2);
		vec.pushBack(3);
		auto element = vec.popBack();
		EXPECT_EQ(3, element);
	}
}
