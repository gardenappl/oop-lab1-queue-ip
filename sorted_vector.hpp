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
size_t sorted_vector<T>::insert(T&& element)
{
	this->size++;
	this->resize_if_needed();
	int i = this->size - 1;
	for (; i > 0; i--)
	{
		//sort elements in reverse order
		if(!this->sort_comparator(this->data[i - 1], element))
		{
//			std::cout << data[i - 1] << " is bigger than " << element << std::endl;
			this->data[i] = this->data[i - 1];
		}
		else
		{
			break;
		}
	}
//	std::cout << "Inserting " << element << " at " << i << std::endl;
	this->data[i] = element;
	return i;
}

template<typename T>
size_t sorted_vector<T>::get_size() const
{
	return vector<T>::get_size();
}

template<typename T>
T sorted_vector<T>::pop()
{
	return vector<T>::pop();
}

template<typename T>
const T* sorted_vector<T>::get_pointer(size_t index) const
{
	return vector<T>::get_pointer(index);
}

template<typename T>
const T& sorted_vector<T>::operator[](size_t index) const
{
	return vector<T>::operator[](index);
}
