#pragma once

namespace ansa::constraints
{
	template <typename T>
	concept Indexable = requires(T t, std::size_t index)
	{
		t[index];
	};

	template <typename T>
	concept GreaterThan = requires(T a, T b)
	{
		{ a > b } -> std::convertible_to<bool>;
	};

	template <typename T>
	concept LessThan = requires(T a, T b)
	{
		{ a < b } -> std::convertible_to<bool>;
	};

	template <typename T>
	concept IndexableGreaterThan = Indexable<T> && GreaterThan<T>;
	template <typename T>
	concept IterableGreaterThan = std::ranges::range<T> && GreaterThan<std::ranges::range_value_t<T>>;

	template <typename T>
	concept IndexableLessThan = Indexable<T> && LessThan<T>;
	template <typename T>
	concept IterableLessThan = std::ranges::range<T> && LessThan<std::ranges::range_value_t<T>>;

	template <typename T>
	concept IterativeSortableContainer = (IndexableGreaterThan<T> || IndexableLessThan<T>)
	                                     ||
	                                     (IterableGreaterThan<T> || IterableLessThan<T>);
}
