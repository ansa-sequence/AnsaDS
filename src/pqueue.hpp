#pragma once
#include <vector>

namespace ansa
{
	// This data structure represents Heap with Min Heap property.
	// Min heap property mean, what in root we have minimal element.
	template <typename T>
	struct Pqueue
	{
		void insert(const T& x)
		{
			mTree.push_back(x);
			int index = static_cast<int>(mTree.size() - 1);
			while (index > 0 && mTree[index] < mTree[getParent(index)])
			{
				std::swap(mTree[index], mTree[getParent(index)]);
				index = getParent(index);
			}
		}

		T removeMinElement()
		{
			auto res = mTree[0];
			mTree[0] = mTree[mTree.size() - 1];
			mTree.erase(mTree.begin() + (mTree.size() - 1));
			int index = 0;
			while (true)
			{
				int j = index;
				if (const int left = getLeft(index); left < mTree.size() && mTree[left] < mTree[j])
				{
					j = left;
				}
				if (const int right = getRight(index); right < mTree.size() && mTree[right] < mTree[j])
				{
					j = right;
				}
				if (j == index)
				{
					break;
				}
				std::swap(mTree[index], mTree[j]);
				index = j;
			}

			return res;
		}

	private:
		std::size_t getParent(const std::size_t index) const
		{
			return index <= 0 || index > mTree.size() ? -1 : (index - 1) / 2;
		}

		std::size_t getLeft(const std::size_t index) const
		{
			const std::size_t left = 2 * index + 1;
			return left >= mTree.size() ? -1 : left;
		}

		std::size_t getRight(const std::size_t index) const
		{
			const std::size_t right = 2 * index + 2;
			return right >= mTree.size() ? -1 : right;
		}

	private:
		std::vector<int> mTree;
	};
}
