#include <functional>
#include <iostream>
#include "algorithms.hpp"

int main()
{
	std::vector<int> vec{ 5,2,4,6,1,3 };
	const auto cmp = [](const auto& first, const auto& second) { return first < second;  };
	ansa_algo::InsertionSort(vec, cmp);
	for(const auto& element : vec)
	{
		std::cout << element << ' ';
	}
}