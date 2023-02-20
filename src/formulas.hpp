#pragma once

namespace ansa
{
	inline int Power(const int num, const int degree)
	{
		if (degree == 0) return 1;
		const int x = Power(num, degree / 2);
		if (degree % 2 == 0) return x * x;
		return num * (x * x);
	}
}
