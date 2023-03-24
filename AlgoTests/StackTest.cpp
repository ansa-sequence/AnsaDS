#include "gtest/gtest.h"
#include "../src/stack.hpp"

namespace stackTests
{
	using namespace ansa;

	class StackTest : public testing::Test
	{
	protected:
		Stack<int> createStack(const std::initializer_list<int>& elements) const { return Stack<int>(elements); }
	};

	TEST_F(StackTest, PushPopTest)
	{
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

	TEST_F(StackTest, TopTest)
	{
		auto stack = createStack({1, 2, 3});

		ASSERT_EQ(stack.top(), 3);

		stack.pop();
		ASSERT_EQ(stack.top(), 2);

		stack.pop();
		ASSERT_EQ(stack.top(), 1);

		stack.pop();
		EXPECT_THROW(stack.pop(), std::length_error);
	}

	TEST_F(StackTest, EmptyTest)
	{
		Stack<int> s({});

		ASSERT_TRUE(s.empty());

		s.push(1);
		ASSERT_FALSE(s.empty());

		s.pop();
		ASSERT_TRUE(s.empty());
	}

	TEST_F(StackTest, SizeTest)
	{
		auto s = createStack({1, 2, 3});

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

		EXPECT_THROW(s.pop(), std::length_error);
	}
}
