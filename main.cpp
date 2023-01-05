#include <iostream>

#include "src/datastructures.hpp"

int main()
{
	auto node    = ansa_algo::ListNode<int>(1);
	auto current = new ansa_algo::ListNode<int>();
	while (current != nullptr)
	{
		current = current->next;
	}
}
