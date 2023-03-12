#pragma once

#include <cassert>
#include <memory>
#include <iostream>

namespace ansa
{
	template <typename T>
	struct AnsaVector
	{
		template <std::size_t N>
		explicit AnsaVector(T (&source)[N])
		{
			mSize     = N;
			mCapacity = N * 2;
			mData     = std::make_unique<T[]>(mSize * 2);
			std::copy(source, source + N, mData.get());
		}


		AnsaVector() = default;

		void pushBack(const T& element)
		{
			if (mSize == 0)
			{
				mCapacity = 2;
				mData     = std::make_unique<T[]>(mCapacity);
			}
			else if (mSize == mCapacity)
			{
				mCapacity *= 2;
				auto newSubarray = std::make_unique<T[]>(mCapacity);
				auto ptr         = mData.get();
				std::move(ptr, ptr + mSize, newSubarray.get());
				mData = std::move(newSubarray);
			}
			mData.get()[mSize++] = std::move(element);
		}

		void erase(const T& target)
		{
			auto ptr = mData.get();
			auto pos = find(target);
			if (pos != std::numeric_limits<std::size_t>::max())
			{
				for (std::size_t index = pos; index < mSize - 1; ++index)
				{
					ptr[index] = ptr[index + 1];
				}
				--mSize;
			}
		}

		void erase(const std::size_t pos)
		{
			if (pos < mSize)
			{
				auto ptr = mData.get();
				for (std::size_t index = pos; index < mSize - 1; ++index)
				{
					ptr[index] = ptr[index + 1];
				}
				--mSize;
			}
		}

		T popBack()
		{
			if (mSize == 0)
			{
				throw std::out_of_range("Vector is empty!");
			}
			T element = std::move(mData.get()[--mSize]);
			return element;
		}

		std::size_t find(const T& target)
		{
			const auto ptr = mData.get();
			for (std::size_t index = 0; index < mSize; ++index)
			{
				if (ptr[index] == target)
				{
					return index;
				}
			}
			return std::numeric_limits<std::size_t>::max();
		}

		std::size_t size() const { return mSize; }
		std::size_t capacity() const { return mCapacity; }
		void        resize(const std::size_t newSize) { mSize = newSize; }
		bool        isEmpty() const { return mSize == 0; }

		auto& at(const std::size_t index)
		{
			assert(index < mSize);
			return mData[index];
		}

		void debug() const
		{
			auto ptr = mData.get();
			for (std::size_t i = 0; i < mSize; ++i)
			{
				std::cout << ptr[i] << ' ';
			}
		}

	private:
		std::unique_ptr<T[]> mData;
		std::size_t          mSize{};
		std::size_t          mCapacity{};
	};
}
