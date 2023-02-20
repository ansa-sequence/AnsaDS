#pragma once
#include <string>

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
}
