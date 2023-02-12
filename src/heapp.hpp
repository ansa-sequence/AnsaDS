#pragma once
#include <vector>
#include <iostream>

namespace ansa_algo
{
	template <typename T>
	struct Heap
	{
		Heap(const std::initializer_list<T>& values) : mStorage{values}
		{
		}

		/**
		 * \brief Retrieves the index of the parent element in a binary heap
		 * \param index The index of the element in the heap
		 * \return The index of the parent element, or std::size_t overflow if the index is invalid
		 */
		std::size_t getParent(std::size_t index) const
		{
			return index <= 0 || index > mStorage.size() ? -1 : (index - 1) / 2;
		}

		/**
		 * \brief Retrieves the index of the left child element in a binary heap
		 * \param index The index of the element in the heap
		 * \return The index of the left child element, or std::size_t overflow if the child does not exist
		 */
		std::size_t getLeft(std::size_t index) const
		{
			std::size_t left = 2 * index + 1;
			return left >= mStorage.size() ? -1 : left;
		}

		/**
		 * \brief Retrieves the index of the right child element in a binary heap
		 * \param index The index of the element in the heap
		 * \return The index of the right child element, or std::size_t overflow if the child does not exist
		 */
		std::size_t getRight(std::size_t index) const
		{
			std::size_t right = 2 * index + 2;
			return right >= mStorage.size() ? -1 : right;
		}

		/**
		* \brief Maintains the heap property of a binary heap.
		* \param index The index of the element to start heapifying from.
		*
		* This method compares the element at the given `index` to its left and right children,
		* and swaps the element with the largest child if the heap property is violated.
		* The process continues recursively until the heap property is satisfied.
		*/
		void heapify(std::size_t index, std::size_t blockerSize = -1)
		{
			std::size_t       left      = getLeft(index);
			std::size_t       right     = getRight(index);
			std::size_t       largest   = index;
			const std::size_t validSize = blockerSize != (0u - 1) ? blockerSize : mStorage.size();

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
