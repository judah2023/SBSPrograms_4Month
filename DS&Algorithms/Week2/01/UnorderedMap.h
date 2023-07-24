#pragma once
#include <vector>
#include <list>
template<typename Key, typename Value>
class UnorderedMap
{
	enum class State
	{
		NONE,
		VISITED,
		DELETED
	};

private:
	std::vector<std::pair<Key,Value>> container;
	std::vector<State> stateList;
	std::list<size_t> bucketList;
	size_t size;
	size_t capacity;
	size_t primeKey;

	size_t HashFunction(Key key)
	{
		size_t hash1 = Hash1(key);
		size_t hash2 = Hash2(key);
		size_t hash = hash1;
		while (stateList[hash] != State::NONE)
		{
			if (container[hash].first == key)
			{
				if (stateList[hash] == State::DELETED)
				{
					hash = hash1;
					while (stateList[hash] == State::VISITED)
						hash = (hash + hash2) % capacity;
				}
				break;
			}
			hash = (hash + hash2) % capacity;
		}
		return hash;
	}

	size_t Hash1(Key key)
	{
		return key % capacity;
	}

	size_t Hash2(Key key)
	{
		return primeKey - (key % primeKey);
	}

	void ReHashing()
	{
		capacity <<= 1;
		container.resize(capacity);
		stateList.resize(capacity, State::NONE);
		size_t idx;
		for (auto it : bucketList)
		{
			std::pair<Key, Value> elem = container[it];

			idx = HashFunction(it);
			stateList[idx] = State::VISITED;
			container[idx] = std::make_pair(elem.first, elem.second);
		}
	}

public:
	UnorderedMap() : size(0), capacity(1024), primeKey(1021)
	{
		container.resize(capacity);
		stateList.resize(capacity, State::NONE);
	}

	~UnorderedMap() = default;

	void Insert(Key key, Value value)
	{
		if (size >= capacity / 2)
		{
			ReHashing();
		}

		size_t idx = HashFunction(key);
		if (stateList[idx] != State::VISITED)
		{
			stateList[idx] = State::VISITED;
			container[idx] = std::make_pair(key, value);
			bucketList.push_back(idx);
			size++;
		}
		else
		{
			container[idx].second = value;
		}
		
	}

	void Delete(Key key)
	{
		size_t idx = HashFunction(key);
		if (stateList[idx] == State::VISITED)
		{
			stateList[idx] = State::DELETED;
			auto iter = bucketList.begin();
			for (iter; iter != bucketList.end(); iter++)
				if (*iter = idx)
					break;
			bucketList.erase(iter);
			size--;
		}
	}

	std::pair<Key, Value>* Find(Key key)
	{
		size_t idx = HashFunction(key);
		if (container[idx].first == key && stateList[idx] == State::VISITED)
			return (container.data() + idx);

		return nullptr;
	}

	Value& operator[](Key key)
	{
		size_t idx = HashFunction(key);
		if (stateList[idx] != State::VISITED)
			Insert(key, 0);

		return container[idx].second;
	}
};
