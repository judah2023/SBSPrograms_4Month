#pragma once
#include <iostream>
template<typename Key>
class CircleQueue
{
	enum Constants { SIZE = 100 };

private:
	Key* buffer;
	size_t front;
	size_t rear;
	size_t size;


public:
	CircleQueue() :
		buffer(new Key[SIZE]), front(0), rear(0), size(0)
	{}
	~CircleQueue() { delete[] buffer; }

	inline void Push(Key&& data)
	{
		if (IsFull())
			throw std::out_of_range("\n스택이 가득 차있습니다.");

		buffer[rear] = data;
		rear = (rear + 1) % SIZE;
		size++;
	}

	void Pop()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		front = (front + 1) % SIZE;
		size--;
	}

	Key& Front()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		return buffer[front];
	}

	Key& Back()
	{
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		return buffer[(rear + SIZE - 1) % SiZE];
	}

	size_t Size() { return size; }

	bool Empty() { return size == 0; }
	bool IsFull() { return size = SIZE; }

};