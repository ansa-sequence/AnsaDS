#pragma once
#include <string>
#include <vector>

namespace ansa
{
	// O(mn)
	inline std::size_t FindSubstring(const std::string& sentence, const std::string& word)
	{
		for (std::size_t i = 0; i <= (sentence.size() - word.size()); ++i)
		{
			std::size_t j = 0;
			while ((j < word.size()) && (sentence[i + j] == word[j]))
			{
				++j;
			}
			if (j == word.size())
			{
				return i;
			}
		}
		return -1;
	}

	template <typename T>
	int BinarySearch(const std::vector<T>& vec, const T& target)
	{
		int low  = 0;
		int high = vec.size() - 1;

		while (low <= high)
		{
			const int mid = (low + high) / 2;

			if (vec[mid] == target)
			{
				return mid;
			}
			if (vec[mid] < target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}

		// If we get here, the target element is not in the vector
		return -1;
	}
}
