#include "../src/searching.hpp"
#include "gtest/gtest.h"

namespace searchingTests
{
	TEST(PlainSearch, ExistWord)
	{
		const std::string& sentence = "abaababbaba";
		const std::string& word     = "abba";

		const auto result = ansa::FindSubstring(sentence, word);
		ASSERT_EQ(result, 5);
	}
}
