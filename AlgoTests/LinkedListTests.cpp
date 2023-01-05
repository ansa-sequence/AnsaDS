#include "gtest/gtest.h"
#include "../datastructures.hpp"

namespace linkedListTest
{
	TEST(InsertionIntoBegin, Insertion)
	{
		// Arrange
		const auto list = new ansa_algo::LinkedList<int>();
		list->insertionBegin(4);
		// Act
		const auto result = list->getNode(4);
		// Assert
		EXPECT_EQ(4, result->val);
	}

	TEST(insertionIntoEnd, Insertion)
	{
		// Arrange
		const auto list = new ansa_algo::LinkedList<int>();
		list->insertionEnd(4);
		// Act
		const auto result = list->getNode(4);
		// Assert
		EXPECT_EQ(4, result->val);
	}
}
