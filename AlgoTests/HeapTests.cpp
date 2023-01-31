#include <gtest/gtest.h>
#include "../src/heapp.hpp"

namespace heapTests
{
	TEST(HeapTest, TestGetParent)
	{
		const ansa_algo::Heap heap({3, 2, 1, 7, 8, 4, 10, 16, 12});

		EXPECT_EQ(heap.getParent(0), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getParent(1), 0);
		EXPECT_EQ(heap.getParent(2), 0);
		EXPECT_EQ(heap.getParent(3), 1);
		EXPECT_EQ(heap.getParent(4), 1);
		EXPECT_EQ(heap.getParent(5), 2);
		EXPECT_EQ(heap.getParent(6), 2);
		EXPECT_EQ(heap.getParent(7), 3);
		EXPECT_EQ(heap.getParent(8), 3);
	}

	TEST(HeapTest, TestGetLeft)
	{
		const ansa_algo::Heap heap({3, 2, 1, 7, 8, 4, 10, 16, 12});

		EXPECT_EQ(heap.getLeft(0), 1);
		EXPECT_EQ(heap.getLeft(1), 3);
		EXPECT_EQ(heap.getLeft(2), 5);
		EXPECT_EQ(heap.getLeft(3), 7);
		EXPECT_EQ(heap.getLeft(4), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getLeft(5), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getLeft(6), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getLeft(7), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getLeft(8), static_cast<std::size_t>(-1));
	}

	TEST(HeapTest, TestGetRight)
	{
		const ansa_algo::Heap heap({3, 2, 1, 7, 8, 4, 10, 16, 12});

		EXPECT_EQ(heap.getRight(0), 2);
		EXPECT_EQ(heap.getRight(1), 4);
		EXPECT_EQ(heap.getRight(2), 6);
		EXPECT_EQ(heap.getRight(3), 8);
		EXPECT_EQ(heap.getRight(4), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getRight(5), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getRight(6), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getRight(7), static_cast<std::size_t>(-1));
		EXPECT_EQ(heap.getRight(8), static_cast<std::size_t>(-1));
	}

	TEST(Sorting, ValidBuild)
	{
		// Act
		auto object = ansa_algo::Heap({4, 1, 3, 2, 16, 9, 10, 14, 8, 7});
		// Arrange
		object.buildHeap();
		const auto& heap           = object.getHeap();
		const auto  equalityObject = std::vector({16, 14, 10, 8, 7, 9, 3, 2, 4, 1});
		// Assert
		EXPECT_EQ(equalityObject, heap);
	}
}
