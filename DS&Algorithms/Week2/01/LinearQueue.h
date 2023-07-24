#pragma once
template<typename T>
class LinearQueue
{
	enum Constants { SIZE = 5 };

private:
	size_t front;
	size_t rear;
	size_t size;
	T container[SIZE];

public:
	LinearQueue() : front(0), rear(0), size(0) {};
	~LinearQueue() {};

	void Push(T data)
	{
		if (rear < SIZE)
		{
			container[rear++] = data;
			size++;
		}
	}

	void Pop() 
	{
		if (!Empty())
		{
			front++;
			size--;
		}
	}

	size_t Size() { return size; }
	bool Empty() { return size == 0; }

	T& Front()
	{
		if (!Empty())
			return container[front];
	}

	T& Back()
	{
		if (!Empty())
			return container[rear - 1];
	}
};

