#include <iostream>

struct ListNode
{
	int       val;
	ListNode* next;

	ListNode() : val(0), next(nullptr)
	{
	}

	ListNode(int x) : val(x), next(nullptr)
	{
	}

	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};

struct LinkedList
{
	ListNode*   head = nullptr;
	std::size_t size = 0;

	void print()
	{
		auto current = head;
		while (current != nullptr)
		{
			std::cout << current->val << ' ';
			current = current->next;
		}
		std::cout << '\n';
	}

	void insertionBegin(int val)
	{
		insertAtIndex(0, val);
	}

	void insertionEnd(int val)
	{
		auto current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new ListNode(val);
		++size;
	}

	void insertAtIndex(std::size_t index, int val)
	{
		if (index > size || index < 0)
		{
			return;
		}

		if (index == 0)
		{
			const auto current = head;
			const auto newNode = new ListNode(val);
			if (index == 0)
			{
				newNode->next = current;
				head          = newNode;
				++size;
			}
		}
		else
		{
			/*
			 * For example we have a node with following structure :
			 * 1 --> 2 --> 3 --> 4
			 * We need to insert in position 1 new element
			 * For it, we will iterate through the list and save current node.
			 * After that, we create new node with some value, in our case it be a 5.
			 * So, we find, what 2 - its 1 position.
			 * Now, we will save node 2 as next node for new node
			 * Node : 5 --> 2
			 * For current node, where we have 2, we will save next element as 5 and next for 5, as we do it will be a 2.
			 */
			auto current = head;
			for (std::size_t i = 0; i < index - 1; ++i)
				current        = current->next;

			const auto newNode = new ListNode(val);
			newNode->next      = current->next;
			current->next      = newNode;
			++size;
		}
	}
};

int main()
{
	const auto list = new LinkedList();
	list->insertionBegin(6);
	list->insertionBegin(7);
	list->insertionBegin(8);
	list->insertAtIndex(1, 40);
	list->insertionEnd(4);

	list->print();
}
