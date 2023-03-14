#pragma once

namespace ansa
{
	template <typename T>
	struct Node
	{
		Node() : next(nullptr), val(0) { }
		explicit Node(int x) : next(nullptr), val(x) { }
		Node(int x, Node* next) : next(next), val(x) { }

		Node* next;
		T     val;
	};
}
