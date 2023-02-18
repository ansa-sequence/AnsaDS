#include <iostream>
#include <vector>

#include "src/constraints.hpp"

struct X
{
	const auto& operator[](std::size_t index) const
	{
		return index;
	}

	int x;
};

bool operator>(const X& lhs, const X& rhs)
{
	return lhs.x > rhs.x;
}

template <ansa::constraints::IterativeSorting I>
bool IsSorted(const I& container)
{
	for (std::size_t i = 0; i < std::size(container) - 1; ++i)
	{
		if (container[i] > container[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::vector<X> elements{{1}, {2}, {4}};
	const auto     result = IsSorted<std::vector<X>>(elements);
	std::cout << std::boolalpha << result << '\n';
}
