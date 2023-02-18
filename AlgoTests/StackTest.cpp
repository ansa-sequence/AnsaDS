#include "gtest/gtest.h"
#include "../src/stack.hpp"

namespace stackTests
{
	TEST(PopOperations, ValidPop)
	{
		// Act
		auto stack = ansa::Stack<int>({});
		// Arrange
		stack.push(5);
		stack.pop();
		// Assert
		EXPECT_EQ(0, stack.size());
	}
}
