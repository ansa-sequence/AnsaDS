#pragma once
#include <iostream>

namespace ansa_algo
{
	template <typename T>
	struct ListNode
	{
		T         val;
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

	template <typename T>
	struct LinkedList
	{
		ListNode<T>* head = nullptr;
		std::size_t  size = 0;

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

		void insertionBegin(T val)
		{
			insertAtIndex(0, val);
		}

		void insertionEnd(T val)
		{
			if (head == nullptr)
			{
				head = new ListNode<T>(val);
				++size;
				return;
			}
			auto current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = new ListNode<T>(val);
			++size;
		}

		void insertAtIndex(std::size_t index, T val)
		{
			if (index > size || index < 0)
			{
				return;
			}

			if (index == 0)
			{
				const auto current = head;
				const auto newNode = new ListNode<T>(val);
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

				const auto newNode = new ListNode<T>(val);
				newNode->next      = current->next;
				current->next      = newNode;
				++size;
			}
		}

		ListNode<T>* getNode(T val)
		{
			auto current = head;
			if (size == 1)
				return head;
			while (current->next != nullptr)
			{
				if (current->val == val)
				{
					return current;
				}
				current = current->next;
			}
			return nullptr;
		}
	};
}
