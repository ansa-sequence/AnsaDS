#include <gtest/gtest.h>

#include "../src/sorting.hpp"


TEST(InsertionSortTest, SortsAscending)
{
	std::vector       input{5, 2, 4, 6, 1, 3};
	const std::vector expected{1, 2, 3, 4, 5, 6};
	ansa::InsertionSort(input, std::greater<int>{});
	ASSERT_EQ(input, expected);
}

TEST(InsertionSortTest, SortsDescending)
{
	std::vector       input{5, 2, 4, 6, 1, 3};
	const std::vector expected{6, 5, 4, 3, 2, 1};
	ansa::InsertionSort(input, std::less<int>{});
	ASSERT_EQ(input, expected);
}

TEST(LinearSearchTest, FindsElement)
{
	const std::vector     input{5, 2, 4, 6, 1, 3};
	constexpr int         element  = 4;
	constexpr std::size_t expected = 2;
	const std::size_t     result   = ansa::LinearSearch(input, element);
	ASSERT_EQ(result, expected);
}

TEST(LinearSearchTest, DoesNotFindElement)
{
	const std::vector     input{5, 2, 4, 6, 1, 3};
	constexpr int         element  = 8;
	constexpr std::size_t expected = -1;
	const std::size_t     result   = ansa::LinearSearch(input, element);
	ASSERT_EQ(result, expected);
}

TEST(MergeSortTest, SortsAscending)
{
	std::vector       input{5, 2, 4, 6, 1, 3};
	const std::vector expected{1, 2, 3, 4, 5, 6};
	ansa::MergeSort(input, 0, input.size());
	ASSERT_EQ(input, expected);
}

TEST(IsSortedTest, IsSortedReturnsTrueForSortedContainer)
{
	const std::vector input{1, 2, 3, 4, 5, 6};
	constexpr bool    expected = true;
	const bool        result   = ansa::IsSorted(input);
	ASSERT_EQ(result, expected);
}

TEST(IsSortedTest, IsSortedReturnsFalseForUnsortedContainer)
{
	const std::vector input{5, 2, 4, 6, 1, 3};
	constexpr bool    expected = false;
	const bool        result   = ansa::IsSorted(input);
	ASSERT_EQ(result, expected);
}

TEST(MinMaxElementTest, FindsMinMaxElements)
{
	const std::vector         input{5, 2, 4, 6, 1, 3};
	const auto                expected = std::make_pair(1, 6);
	const std::pair<int, int> result   = ansa::MinMaxElement(input);
	ASSERT_EQ(result, expected);
}
