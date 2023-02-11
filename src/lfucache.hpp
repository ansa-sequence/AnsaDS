#pragma once

#include <chrono>
#include <unordered_map>

namespace hw
{
	using hwTime = std::chrono::time_point<std::chrono::steady_clock>;

	template <typename Key, typename Value>
	struct LFUCacheTable
	{
		std::unordered_map<Key, std::pair<std::size_t, hwTime>> mMap;
		std::unordered_map<Key, Value>                          mValues;

		auto& operator[](const Key& key)
		{
			return mValues[key];
		}

		auto find(const Key& key)
		{
			return mValues.find(key);
		}

		void insert(const Key& key, const Value& value)
		{
			mValues[key] = value;
			mMap[key]    = {1, std::chrono::steady_clock::now()};
		}

		void erase(const Key& key)
		{
			mMap.erase(key);
			mValues.erase(key);
		}

		std::size_t size() const
		{
			return mValues.size();
		}
	};

	template <typename Key, typename Value>
	struct LFUCache
	{
		explicit LFUCache(std::size_t cacheSize) : mSize(cacheSize)
		{
		}

		void insert(const Key& key, const Value& value)
		{
			if (mCache.size() < mSize)
			{
				mCache.insert(key, value);
				return;
			}

			auto lowFrequency = std::make_pair(Key{}, std::numeric_limits<float>::max());
			for (const auto& [k, v] : mCache.mMap)
			{
				float frequency = static_cast<float>(v.first) / static_cast<float>(mSize);
				if (frequency < lowFrequency.second)
				{
					lowFrequency = {k, frequency};
				}
			}
			mCache.erase(lowFrequency.first);
			mCache.insert(key, value);
		}

	private:
		LFUCacheTable<Key, Value> mCache;
		const std::size_t         mSize;
	};
}
