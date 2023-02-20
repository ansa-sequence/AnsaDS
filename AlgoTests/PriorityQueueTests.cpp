#include "../src/pqueue.hpp"
#include "../src/sorting.hpp"
#include "gtest/gtest.h"

TEST(PriorityQueueSort, Sorting)
{
	const std::vector elements{1, 3, 2, 4, 6, 0};
	ansa::Pqueue<int> queue;
	for (const auto& element : elements)
	{
		queue.insert(element);
	}

	std::vector<int>  result{};
	const std::size_t storageSize = queue.size();
	for (std::size_t i = 0; i < storageSize; ++i)
	{
		result.push_back(queue.removeMinElement());
	}

	ASSERT_EQ(ansa::IsSorted<std::vector<int>>(result), true);
}
