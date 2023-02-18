#include "gtest/gtest.h"
#include "../src/set.hpp"

namespace setTests
{
	TEST(Find, ValidItemFinding)
	{
		// Arrange
		const std::vector items{1, 3, 2, 5, 6, 8, 0};
		auto              set = ansa::StaticSet<int>{};
		set.build(items);
		// Act
		const auto result = set.find(5);
		// Assert
		EXPECT_EQ(5, result);
	}

	TEST(Find, InvalidItemFinding)
	{
		// Arrange
		const std::vector items{1, 3, 2, 5, 6, 8, 0};
		auto              set = ansa::StaticSet<int>{};
		set.build(items);
		// Act
		const auto result = set.find(44);
		// Assert
		EXPECT_EQ(0, result);
	}

	TEST(Find, ValidMinimalElement)
	{
		// Arrange
		const std::vector items{1, 3, 2, 5, 6, 8, 0};
		auto              set = ansa::StaticSet<int>{};
		set.build(items);
		// Act
		const auto result = set.findMin();
		// Assert
		EXPECT_EQ(0, result);
	}

	TEST(Find, InvalidMinimalElement)
	{
		// Arrange
		const auto set = ansa::StaticSet<int>{};
		// Act
		const auto result = set.findMin();
		// ASSERT
		EXPECT_EQ(0, result);
	}
}
