#include "src/heapp.hpp"

int main()
{
	// Act

	auto object = ansa_algo::Heap({4, 1, 3, 2, 16, 9, 10, 14, 8, 7});
	// Arrange
	object.buildHeap();
	object.print();
	//
}
