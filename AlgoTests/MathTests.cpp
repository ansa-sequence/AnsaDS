#include "../src/formulas.hpp"
#include "gtest/gtest.h"

namespace mathTests
{
	TEST(Power, ValidDegree)
	{
		const int x = ansa::Power(2, 2);
		ASSERT_EQ(x, 4);
	}
}
