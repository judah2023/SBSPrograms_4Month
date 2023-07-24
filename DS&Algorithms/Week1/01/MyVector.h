#pragma once
template<typename T>
class MyVector
{
private:
	T* container;
	size_t size;
	size_t capacity;
public:
	MyVector() : container(nullptr), size(0), capacity(0) {};
	explicit MyVector(size_t const size) : container(new T[size]), size(size), capacity(size) 
	{
		for (size_t i = 0; i < size; i++)
			container[i] = 0;
	}

	MyVector(MyVector<T> const& copy);
	
	~MyVector()
	{
		if (container != nullptr)
			delete[] container;
	}

	T& operator[](size_t idx)
	{
		if (idx < size)
			return container[idx];
	}

	T& at(size_t idx)
	{
		if (idx >= size)
			throw std::out_of_range("OUT OF RANGE!");

		return container[idx];
	}

	T Front() 
	{
		if (size != 0)
			return container[0];
	}

	T Back() 
	{ 
		if (size != 0)
			return container[size - 1]; 
	}

	size_t Size() { return size; }
	size_t Capacity() { return capacity; }

	void Clear() { size = 0; }

	void PushBack(T const& data);
	void PopBack();

	void Resize(size_t const& newSize);
	void Reserve(size_t const& newCapacity);
};

template<typename T>
inline MyVector<T>::MyVector(MyVector<T> const& copy) : container(new T[copy.capacity]), size(copy.size), capacity(copy.capacity)
{
	for (size_t i = 0; i < copy.size; i++)
		container[i] = copy.container[i];
}

template<typename T>
inline void MyVector<T>::PushBack(T const& data)
{
	if (size == capacity)
	{
		size_t newCapacity = (size_t)(capacity * 1.5 >= 2 ? capacity * 1.5 : capacity + 1);

		T* newContainer = new T[newCapacity];
		for (size_t i = 0; i < size; i++)
			newContainer[i] = container[i];

		delete[] container;
		container = newContainer;
		capacity = newCapacity;
	}

	container[size++] = data;
}

template<typename T>
inline void MyVector<T>::PopBack()
{
	if (size > 0)
		size--;
}

template<typename T>
inline void MyVector<T>::Resize(size_t const& newSize)
{
	if (newSize > size)
	{
		T* newContaioner = new T[newSize];

		for (size_t i = 0; i < size; i++)
			newContaioner[i] = container[i];

		delete[] container;

		container = newContaioner;
		capacity = newSize;
	}

	size = newSize;
}