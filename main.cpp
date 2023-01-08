#include <iostream>

struct ListNode
{
	int       val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr)
	{
	}
};

class Solution
{
public:
	bool hasCycle(ListNode* head)
	{
		auto header  = head;
		auto current = head;
		while (current != nullptr)
		{
			current = current->next;
			if (current == header)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution solution;
	auto     node    = new ListNode(1);
	node->next       = new ListNode(2);
	node->next->next = node;
	solution.hasCycle(node);
}
