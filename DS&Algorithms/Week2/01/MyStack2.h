#pragma once
#include <deque>
template<typename Key>
class MyStack2
{
private:
	std::deque<Key> buffer;

public:
	MyStack2() = default;
	~MyStack2() = default;

	void Push(Key&& data) { buffer.push_back(data); }
	void Pop() { buffer.pop_back(); }

	Key& Top() { return buffer.back(); }

	size_t Size() { return buffer.size(); }

	bool Empty() { return buffer.empty(); }
};