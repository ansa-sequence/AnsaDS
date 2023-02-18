#pragma once
#include <vector>
#include <iostream>

namespace ansa
{
	// TODO : Please in near feature rewrite this to one Heap data structure with template parameter which will be change Heapify property.
	template <typename T>
	struct Heap
	{
		Heap(const std::initializer_list<T>& values) : mStorage{values}
		{
		}

		std::size_t getParent(std::size_t index) const
		{
			return index <= 0 || index > mStorage.size() ? -1 : (index - 1) / 2;
		}

		std::size_t getLeft(std::size_t index) const
		{
			std::size_t left = 2 * index + 1;
			return left >= mStorage.size() ? -1 : left;
		}

		std::size_t getRight(std::size_t index) const
		{
			std::size_t right = 2 * index + 2;
			return right >= mStorage.size() ? -1 : right;
		}

		void heapify(std::size_t index, std::size_t blockerSize = -1)
		{
			std::size_t       left      = getLeft(index);
			std::size_t       right     = getRight(index);
			std::size_t       largest   = index;
			const std::size_t validSize = blockerSize != (static_cast<size_t>(0) - 1) ? blockerSize : mStorage.size();

			if (left < validSize && mStorage[left] > mStorage[index])
			{
				largest = left;
			}

			if (right < validSize && mStorage[right] > mStorage[largest])
			{
				largest = right;
			}

			if (largest != index)
			{
				std::swap(mStorage[index], mStorage[largest]);
				heapify(largest, validSize);
			}
		}

		void buildHeap()
		{
			for (int i = static_cast<int>(mStorage.size() / 2 - 1); i >= 0; --i)
			{
				heapify(i);
			}
		}

		void heapsort()
		{
			buildHeap();
			std::size_t heapSize = mStorage.size();
			for (int i = static_cast<int>(mStorage.size() - 1); i >= 0; --i)
			{
				std::swap(mStorage[0], mStorage[i]);
				--heapSize;
				heapify(0, heapSize);
			}
		}

		const std::vector<T>& getHeap() const { return mStorage; }

		void print()
		{
			for (const auto& element : mStorage)
			{
				std::cout << element << ' ';
			}
		}

	private:
		std::vector<T> mStorage;
	};
}
