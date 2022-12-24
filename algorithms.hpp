#pragma once
#include <vector>

namespace ansa_algo
{
	template<typename Compare>
	inline void InsertionSort(std::vector<int>& vec, Compare cmp)
	{
		for(int i = 1; i < vec.size(); ++i)
		{
			const auto key = vec[i];
			int j = i - 1;
			while(j >= 0 && cmp(vec[j],key))
			{
				vec[j + 1] = vec[j];
				j -= 1;
			}
			vec[j + 1] = key;
		}
	}

	inline std::size_t LinearSearch(const std::vector<int>& vec, int element)
	{
		for(std::size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == element)
				return i;
		}

		return -1;
	}
}
