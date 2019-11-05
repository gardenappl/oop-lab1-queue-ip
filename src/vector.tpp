#pragma once

#include <stdexcept>


template<typename T>
vector<T>::~vector()
{
	delete data;
}

template<typename T>
void vector<T>::resize_and_copy(int new_capacity)
{
	//std::cout << "(changing from " << capacity << " to " << new_capacity << ')' << std::endl;

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
size_t vector<T>::push_back(const T& element)
{
	size++;
	resize_if_needed();
	data[size - 1] = element;
	return size - 1;
}

template<typename T>
T vector<T>::pop_back()
{
	if(size == 0)
		throw std::out_of_range("Tried to pop_back empty vector");
	T element = data[size - 1];
	size--;
	resize_if_needed();
	return element;
}

template<typename T>
T& vector<T>::operator [](std::size_t index) const
{
	if(index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, vector<T> vec)
{
	if(vec.get_size() == 0) {
		os << "<empty>";
		return os;
	}

	os << "{ " << vec[0].element;

	for(int i = 1; i < vec.get_size(); i++) {
		os << ", " << vec[i].element;
	}
	os << " }";
	return os;
}
