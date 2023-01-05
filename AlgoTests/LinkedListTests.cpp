#include <random>

#include "gtest/gtest.h"
#include "../src/datastructures.hpp"

namespace linkedListTest
{
	TEST(Insertion, InsertionIntoBegin)
	{
		// Arrange
		const auto list = new ansa_algo::LinkedList<int>();
		list->insertionBegin(4);
		// Act
		const auto result = list->getNode(4);
		// Assert
		EXPECT_EQ(4, result->val);
	}

	TEST(Insertion, insertionIntoEnd)
	{
		// Arrange
		const auto list = new ansa_algo::LinkedList<int>();
		list->insertionEnd(4);
		// Act
		const auto result = list->getNode(4);
		// Assert
		EXPECT_EQ(4, result->val);
	}

	TEST(Insertion, InsertionAtUnreachableIndex)
	{
		// Arrange
		const auto    list  = new ansa_algo::LinkedList<int>();
		constexpr int val   = 1;
		constexpr int index = 10;
		list->insertAtIndex(index, val);
		// Act
		const auto result = list->getNode(index);
		// Assert
		EXPECT_EQ(nullptr, result);
	}

	TEST(Insertion, InsertionAtReachableIndex)
	{
		// Arrange
		const auto    list  = new ansa_algo::LinkedList<int>();
		constexpr int val   = 1;
		constexpr int index = 0;
		list->insertAtIndex(index, val);
		// Act
		const auto result = list->getNode(val);
		// Assert
		EXPECT_EQ(1, result->val);
	}

	TEST(Insertion, InsertionInMiddle)
	{
		// Arrange
		const auto list = new ansa_algo::LinkedList<int>();

		std::random_device                 rd;
		std::mt19937                       mt(rd());
		std::uniform_int_distribution<int> distribution(10, 10000);
		for (int i = 0; i < distribution(mt); ++i)
		{
			list->insertionEnd(distribution(mt));
		}
		constexpr int val   = 1;
		const int     index = static_cast<int>(list->getSize() / 2);
		// Act
		list->insertAtIndex(index, val);
		const auto result = list->getNode(val);
		// Assert
		EXPECT_EQ(1, result->val);
	}
}
