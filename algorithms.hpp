#pragma once
#include <vector>

namespace ansa_algo
{
	template <typename Compare>
	void InsertionSort(std::vector<int>& vec, Compare cmp)
	{
		for (int i = 1; i < vec.size(); ++i)
		{
			const auto key = vec[i];
			int        j   = i - 1;
			while (j >= 0 && cmp(vec[j], key))
			{
				vec[j + 1] = vec[j];
				j -= 1;
			}
			vec[j + 1] = key;
		}
	}

	inline std::size_t LinearSearch(const std::vector<int>& vec, int element)
	{
		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == element)
				return i;
		}

		return -1;
	}

	inline void Merge(std::vector<int>& array, std::size_t left, std::size_t mid, std::size_t right)
	{
		auto lefter  = std::vector<int>(array.begin() + left, array.begin() + mid);
		auto righter = std::vector<int>(array.begin() + mid, array.begin() + right);

		lefter.push_back(std::numeric_limits<int>::max());
		righter.push_back(std::numeric_limits<int>::max());

		std::size_t i = 0;
		std::size_t j = 0;
		for (std::size_t current = left; current < right; ++current)
		{
			if (lefter[i] <= righter[j])
			{
				array[current] = lefter[i];
				++i;
			}
			else
			{
				array[current] = righter[j];
				++j;
			}
		}
	}

	inline void MergeSort(std::vector<int>& array, std::size_t left, std::size_t right)
	{
		if (left + 1 < right)
		{
			const auto mid = (right + left) / 2;
			MergeSort(array, left, mid);
			MergeSort(array, mid, right);
			Merge(array, left, mid, right);
		}
	}

	template <typename T>
	auto MinMaxElement(const std::vector<T>& elements)
	{
		std::pair<int, int> result{std::numeric_limits<T>::max(), std::numeric_limits<T>::min()};
		for (const auto& element : elements)
		{
			result.first  = std::min(result.first, element);
			result.second = std::max(result.second, element);
		}
	}
}
