#pragma once
#include <iostream>
template<typename Key>
class CircleQueue
{
	enum Constants { SIZE = 100 };

private:
	Key* buffer;
	size_t rear;

public:
	CircleQueue() : 
		buffer(new Key[SIZE]), 
		rear(0) 
	{}
	~CircleQueue() { delete[] buffer; }

	inline void Push(Key&& data) 
	{ 
		if (IsFull())
			throw std::out_of_range("\n스택이 가득 차있습니다.");
			
		buffer[rear++] = data;
	}

	void Pop() 
	{ 
		if (Empty())
			throw std::out_of_range("\n스택이 비어있습니다.");

		rear--;
	}

	Key& Top() 
	{ 
		if (Empty()) 
			throw std::out_of_range("\n스택이 비어있습니다.");
		
		return buffer[rear - 1]; 
	}

	size_t Size() { return rear; }

	bool Empty() { return rear == 0; }
	bool IsFull() { return rear == SIZE; }

};