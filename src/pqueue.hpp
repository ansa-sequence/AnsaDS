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
			std::size_t index = static_cast<int>(mTree.size() - 1);
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
			mTree.pop_back();
			std::size_t index = 0;
			while (true)
			{
				std::size_t j = index;
				if (const std::size_t left = getLeft(index); left < mTree.size() && mTree[left] < mTree[j])
				{
					j = left;
				}
				if (const std::size_t right = getRight(index); right < mTree.size() && mTree[right] < mTree[j])
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

		std::size_t size() const { return mTree.size(); }

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
