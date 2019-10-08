#pragma once

template<typename T>
sorted_vector<T>::sorted_vector()
	: sort_comparator(standard_comparator<T>)
{}

template<typename T>
sorted_vector<T>::sorted_vector(comparator<T> comparator)
	: sort_comparator(comparator)
{}

template<typename T>
sorted_vector<T>::~sorted_vector()
{
	delete data;
}

template<typename T>
void sorted_vector<T>::resize_and_copy(int new_capacity)
{
#if DEBUG
	std::cout << "(changing from " << capacity << " to " << new_capacity << ')' << std::endl;
#endif
	T* new_array = new T[new_capacity];
	std::copy(data, data + size, new_array);
	delete data;
	data = new_array;
	capacity = new_capacity;
}

template<typename T>
void sorted_vector<T>::resize_if_needed()
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
size_t sorted_vector<T>::get_size() const
{
	return size;
}

template<typename T>
void sorted_vector<T>::insert(T&& element)
{
	size++;
	resize_if_needed();
	int i = size - 1;
	for (; i > 0; i--)
	{
		//sort elements in reverse order
		if(!sort_comparator(data[i - 1], element))
		{
//			std::cout << data[i - 1] << " is bigger than " << element << std::endl;
			data[i] = data[i - 1];
		}
		else
		{
			break;
		}
	}
//	std::cout << "Inserting " << element << " at " << i << std::endl;
	data[i] = element;
}

template<typename T>
T sorted_vector<T>::pop()
{
	T element = data[size - 1];
	size--;
	resize_if_needed();
	return element;
}

template<typename T>
const T& sorted_vector<T>::operator [](std::size_t index) const
{
	return data[index];
}

template<typename T>
T* sorted_vector<T>::get_pointer(std::size_t index) const
{
	return data + index;
}

