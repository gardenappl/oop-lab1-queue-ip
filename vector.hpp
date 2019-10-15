#pragma once



template<typename T>
vector<T>::~vector()
{
	delete data;
}

template<typename T>
void vector<T>::resize_and_copy(int new_capacity)
{
	std::cout << "(changing from " << capacity << " to " << new_capacity << ')' << std::endl;

	T* new_array = new T[new_capacity];
	std::copy(data, data + size, new_array);
	delete data;
	data = new_array;
	capacity = new_capacity;
}

template<typename T>
void vector<T>::resize_if_needed()
{
	if (size > capacity)
	{
		resize_and_copy(capacity * 2);
	}
	else
	{
		if (size <= capacity / 2 && capacity / 2 >= min_capacity)
		{
			resize_and_copy(capacity / 2);
		}
	}
}

template<typename T>
size_t vector<T>::get_size() const
{
	return size;
}

template<typename T>
size_t vector<T>::insert(T&& element)
{
	size++;
	resize_if_needed();
	data[size - 1] = element;
	return size - 1;
}

template<typename T>
T vector<T>::pop()
{
	T element = data[size - 1];
	size--;
	resize_if_needed();
	return element;
}

template<typename T>
T& vector<T>::operator [](std::size_t index) const
{
	return data[index];
}

template<typename T>
T* vector<T>::get_pointer(std::size_t index) const
{
	return data + index;
}

template<typename T>
void vector<T>::resize(std::size_t new_size)
{
	size = new_size;
	resize_if_needed();
}
