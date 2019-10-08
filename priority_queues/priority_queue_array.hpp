#pragma once

template<typename T>
priority_queue_array<T>::priority_queue_array()
	: vector(sorted_vector<element_with_priority<T>>(priority_comparator<T>))
{}


template<typename T>
void priority_queue_array<T>::add(T element, int priority)
{
	vector.insert(element_with_priority<T>(element, priority));
}


template<typename T>
void priority_queue_array<T>::print(std::ostream& os) const
{
	if(vector.get_size() == 0) {
		os << "<empty>";
		return;
	}

	os << "{ " << vector[0].element;

	for(int i = 1; i < vector.get_size(); i++) {
		os << ", " << vector[i].element;
	}
	os << " }";
}

template<typename T>
T* priority_queue_array<T>::peek()
{
	return &(vector.get_pointer(vector.get_size() - 1)->element);
}

template<typename T>
T priority_queue_array<T>::pop()
{
	return vector.pop().element;
}
