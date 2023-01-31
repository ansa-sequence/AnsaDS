#pragma once
#include <iostream>
#include <vector>

namespace ansa_algo
{
	template <typename T>
	struct Stack
	{
		Stack(std::vector<int> elements)
		{
			mData = elements;
		}

		void push(T t)
		{
			mData.push_back(t);
		}

		void pop()
		{
			!mData.empty()
				? mData.erase(mData.begin() + mData.size() - 1)
				: throw std::length_error("Stack does not have elements!\n");
		}

		T top() const
		{
			return !mData.empty() ? *mData.crbegin() : throw std::length_error("Stack does not have elements!\n");
		}

		std::size_t size()
		{
			return mData.size();
		}

		bool empty() const
		{
			return mData.empty();
		}

	private:
		std::vector<T> mData;
	};
}
