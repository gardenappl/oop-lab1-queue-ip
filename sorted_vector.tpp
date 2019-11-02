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
size_t sorted_vector<T>::insert(const T& element)
{
    data_vector.push_back(element);
	size_t i = data_vector.get_size() - 1;
	for (; i > 0; i--)
	{
		if(this->sort_comparator(element, this->data_vector[i - 1]))
		{
//			std::cout << data[i - 1] << " is smaller than " << element << std::endl;
			this->data_vector[i] = this->data_vector[i - 1];
		}
		else
		{
			break;
		}
	}
//	std::cout << "Inserting " << element << " at " << i << std::endl;
	this->data_vector[i] = element;
	return i;
}

template<typename T>
size_t sorted_vector<T>::get_size() const
{
	return data_vector.get_size();
}

template<typename T>
T sorted_vector<T>::pop()
{
	return data_vector.pop_back();
}

template<typename T>
const T& sorted_vector<T>::operator[](size_t index) const
{
	return data_vector[index];
}
