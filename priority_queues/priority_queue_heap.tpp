#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_

template<typename T>
priority_queue_heap<T>::priority_queue_heap(comparator<T>& sort_comparator)
    : priority_queue<T>(sort_comparator), data()
{}

template<typename T>
size_t priority_queue_heap<T>::get_parent_index(size_t index) const
{
	return (index - 1) / 2;
}

template<typename T>
size_t priority_queue_heap<T>::get_left_child_index(size_t index) const
{
	return 2 * index + 1;
}

template<typename T>
size_t priority_queue_heap<T>::get_right_child_index(size_t index) const
{
	return 2 * index + 2;
}

template<typename T>
void priority_queue_heap<T>::print(std::ostream& os) const
{
	if(data.get_size() == 0) {
		os << "<empty>";
		return;
	}

	os << "{ " << data[0];

	for(int i = 1; i < data.get_size(); i++) {
		os << ", " << data[i];
	}
	os << " }";
}

template<typename T>
void priority_queue_heap<T>::add(const T& element)
{
	//Add the element to the bottom level of the heap at the most left.
	size_t index = data.push_back(element);

	while(true)
	{
		//Compare the added element with its parent; if they are in the correct order, stop.
		if(index == 0)
			return;

		size_t parent_index = get_parent_index(index);
		if(this->sort_comparator(data[parent_index], element))
		{
			//std::cout << "Swapping " << data[parent_index].element
			//		<< " " << data[index].element << std::endl;
			std::swap(data[parent_index], data[index]);
			index = parent_index;
		}
		else
			return;
	}
}

template<typename T>
const T& priority_queue_heap<T>::peek() const
{
	return data[0];
}

template<typename T>
T priority_queue_heap<T>::pop()
{
	if (data.get_size() == 0)
		throw std::logic_error("Tried to pop empty stack.");
	else if(data.get_size() == 1)
	    return data.pop_back();

	T root = data[0];
	//Replace root with the last element in heap
	data[0] = data.pop_back();

	//Compare with children, swap with largest child if needed
	int current_index = 0;
	while (true)
	{
		size_t left_index = get_left_child_index(current_index);
		size_t right_index = get_right_child_index(current_index);
		size_t max_index = current_index;
		if (left_index < data.get_size() && this->sort_comparator(data[max_index], data[left_index]))
            max_index = left_index;
		if (right_index < data.get_size() && this->sort_comparator(data[max_index], data[right_index]))
            max_index = right_index;

		if (max_index == current_index)
			break;
		else
		{
			std::swap(data[max_index], data[current_index]);
			current_index = max_index;
		}
	}
	return root;
}



#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_ */
