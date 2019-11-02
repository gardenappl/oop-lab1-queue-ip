#pragma once

template<typename T>
priority_queue_array<T>::priority_queue_array(comparator<T>& sort_comparator)
    : priority_queue<T>(sort_comparator), sorted_data(sorted_vector<T>(sort_comparator))
{}


template<typename T>
void priority_queue_array<T>::add(const T& element)
{
	sorted_data.insert(element);
}


template<typename T>
void priority_queue_array<T>::print(std::ostream& os) const
{
	if(sorted_data.get_size() == 0) {
		os << "<empty>";
		return;
	}

	os << "{ " << sorted_data[sorted_data.get_size() - 1];

	for(int i = sorted_data.get_size() - 2; i >= 0; i--) {
		os << ", " << sorted_data[i];
	}
	os << " }";
}

template<typename T>
const T& priority_queue_array<T>::peek() const
{
	return sorted_data[sorted_data.get_size() - 1];
}

template<typename T>
T priority_queue_array<T>::pop()
{
	return sorted_data.pop();
}
