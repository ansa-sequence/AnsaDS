#pragma once

#include <cassert>
#include <vector>

#include "node.hpp"

namespace ansa
{
	template <typename T>
	struct LinkedList
	{
		explicit LinkedList(Node<T>* init = nullptr) : mHead(init), mSize(init ? 1 : 0) {}

		explicit LinkedList(const std::vector<T>& input) : mHead(nullptr), mSize(input.size())
		{
			if (mSize == 0) return;

			auto current = new Node<T>(input[0]);
			mHead        = current;

			for (std::size_t i = 1; i < mSize; ++i)
			{
				current->next = new Node<T>(input[i]);
				current       = current->next;
			}
		}

		void pushFront(const T& element)
		{
			Node<T>* newHead = new Node<T>(element);
			newHead->next    = mHead;
			mHead            = newHead;
			++mSize;
		}

		void pushEnd(const T& element)
		{
			auto newNode = new Node<T>(element);

			if (!mHead) { mHead = newNode; }
			else
			{
				Node<T>* current = mHead;
				while (current->next) current = current->next;
				current->next = newNode;
			}

			++mSize;
		}

		void popFront()
		{
			if (!mHead) return;

			const auto oldHead = mHead;
			mHead              = mHead->next;
			delete oldHead;
			--mSize;
		}

		void popEnd()
		{
			if (!mHead) { return; }
			if (!mHead->next)
			{
				delete mHead;
				mHead = nullptr;
			}
			else
			{
				auto current = mHead;
				while (current->next->next) { current = current->next; }
				delete current->next;
				current->next = nullptr;
			}
			--mSize;
		}

		void insert(const T& element, const std::size_t index)
		{
			assert(index <= mSize);

			if (index == 0) { pushFront(element); }
			else if (index == mSize) { pushEnd(element); }
			else
			{
				auto newNode = new Node<T>(element);
				auto prev    = findAt(index - 1);

				newNode->next = prev->next;
				prev->next    = newNode;

				++mSize;
			}
		}

		void erase(const std::size_t index)
		{
			assert(index < mSize);

			if (index == 0)
			{
				auto toRemove = mHead;
				mHead         = mHead->next;
				delete toRemove;
			}
			else
			{
				auto prevNode  = findAt(index - 1);
				auto toRemove  = prevNode->next;
				prevNode->next = toRemove->next;
				delete toRemove;
			}

			--mSize;
		}

		Node<T>* find(const T& element)
		{
			auto current = mHead;
			while (current)
			{
				if (current->val == element) { return current; }
				current = current->next;
			}
			return nullptr;
		}

		Node<T>* findAt(std::size_t index)
		{
			assert(index < mSize);
			auto current = mHead;
			for (std::size_t i = 0; i < mSize; ++i)
			{
				if (i == index) { return current; }
				current = current->next;
			}
			return nullptr;
		}

		std::size_t size() const { return mSize; }
		bool        empty() const { return mSize == 0; }

		Node<T>* front() const { return mHead; }

		Node<T>* back() const
		{
			auto current = mHead;
			while (current->next) { current = current->next; }
			return current;
		}

		void reverse()
		{
			Node<T>* prev    = nullptr;
			Node<T>* current = mHead;

			while (current)
			{
				auto next     = current->next;
				current->next = prev;
				prev          = current;
				current       = next;
			}
			mHead = prev;
		}

	private:
		Node<T>*    mHead = nullptr;
		std::size_t mSize{};
	};
}
