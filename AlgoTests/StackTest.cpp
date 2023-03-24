#include "gtest/gtest.h"
#include "../src/stack.hpp"

namespace stackTests
{
	using namespace ansa;

	// Test fixture for the Stack class
	class StackTest : public testing::Test
	{
	protected:
		// Helper function to create a stack with the given elements
		Stack<int> createStack(const std::initializer_list<int>& elements) const { return Stack<int>(elements); }
	};

	// Tests the push and pop methods of the Stack class
	TEST_F(StackTest, PushPopTest)
	{
		// Arrange
		auto s = createStack({1, 2, 3});

		s.push(4);
		ASSERT_EQ(s.top(), 4);

		s.pop();
		ASSERT_EQ(s.top(), 3);

		s.pop();
		ASSERT_EQ(s.top(), 2);

		s.pop();
		ASSERT_EQ(s.top(), 1);

		// Act and Assert
		s.pop();
		EXPECT_THROW(s.top(), std::length_error);
	}

	// Tests the top method of the Stack class
	TEST_F(StackTest, TopTest)
	{
		// Arrange
		auto stack = createStack({1, 2, 3});

		// Act and Assert
		ASSERT_EQ(stack.top(), 3);

		stack.pop();
		ASSERT_EQ(stack.top(), 2);

		stack.pop();
		ASSERT_EQ(stack.top(), 1);

		// Act and Assert
		stack.pop();
		EXPECT_THROW(stack.pop(), std::length_error);
	}

	// Tests the empty method of the Stack class
	TEST_F(StackTest, EmptyTest)
	{
		// Arrange
		Stack<int> s({});

		// Act and Assert
		ASSERT_TRUE(s.empty());

		s.push(1);
		ASSERT_FALSE(s.empty());

		s.pop();
		ASSERT_TRUE(s.empty());
	}

	// Tests the size method of the Stack class
	TEST_F(StackTest, SizeTest)
	{
		// Arrange
		auto s = createStack({1, 2, 3});

		// Act and Assert
		ASSERT_EQ(s.size(), 3);

		s.push(4);
		ASSERT_EQ(s.size(), 4);

		s.pop();
		ASSERT_EQ(s.size(), 3);

		s.pop();
		ASSERT_EQ(s.size(), 2);

		s.pop();
		ASSERT_EQ(s.size(), 1);

		s.pop();

		// Assert and Act
		EXPECT_THROW(s.pop(), std::length_error);
	}
}
