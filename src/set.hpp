#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace ansa_algo
{
	template <typename T>
	struct ISet
	{
		virtual void        build(std::vector<T> elements) = 0;
		virtual std::size_t len() const = 0;
		virtual void        itemOrd() const = 0;
		virtual T           find(T key) const = 0;
		virtual T           findMin() const = 0;
		virtual T           findMax() const = 0;
		virtual             ~ISet() = default;
	};

	template <typename T>
	struct StaticSet : ISet<T>
	{
		void build(std::vector<T> elements) override
		{
			mContainer = elements;
			std::ranges::sort(mContainer);
		}

		std::size_t len() const override
		{
			return mContainer.size();
		}

		void itemOrd() const override
		{
			for (const auto& element : mContainer)
			{
				std::cout << element << ' ';
			}
			std::cout << '\n';
		}

		T find(T key) const override
		{
			std::size_t left  = 0;
			std::size_t right = mContainer.size() - 1;
			while (left <= right)
			{
				std::size_t middle = (left + right) / 2;
				if (mContainer[middle] == key)
				{
					return mContainer[middle];
				}
				if (mContainer[middle] > key)
				{
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
			}
			return T{};
		}

		T findMin() const override
		{
			return !mContainer.empty() ? *mContainer.begin() : T{};
		}

		T findMax() const override
		{
			return !mContainer.empty() ? *mContainer.rbegin() : T{};
		}

	private:
		std::vector<T> mContainer;
	};
}
