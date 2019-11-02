#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_



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

	os << "{ " << data[0].element;

	for(int i = 1; i < data.get_size(); i++) {
		os << ", " << data[i].element;
	}
	os << " }";
}

template<typename T>
void priority_queue_heap<T>::add(T element, int priority)
{
	//Add the element to the bottom level of the heap at the most left.
	size_t index = data.insert(element_with_priority<T>(element, priority));

	while(true)
	{
		//Compare the added element with its parent; if they are in the correct order, stop.
		if(index == 0)
			return;

		size_t parent_index = get_parent_index(index);
		if(data[parent_index].priority > priority)
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
const T* priority_queue_heap<T>::peek()
{
	return &(data[0].element);
}

template<typename T>
T priority_queue_heap<T>::pop()
{
	if (data.get_size() == 0)
		throw std::logic_error("Tried to pop empty stack.");
	T root = data[0].element;
	//Replace root with the last element in heap
	data[0] = data[data.get_size() - 1];
	data.resize(data.get_size() - 1);

	//Compare with children, swap with largest child if needed
	int current_index = 0;
	while (true)
	{
		size_t left_index = get_left_child_index(current_index);
		size_t right_index = get_right_child_index(current_index);
		size_t min_index = current_index;
		if (left_index < data.get_size() && data[left_index].priority < data[min_index].priority)
			min_index = left_index;
		if (right_index < data.get_size() && data[right_index].priority < data[min_index].priority)
			min_index = right_index;

		if (min_index == current_index)
			break;
		else
		{
			std::swap(data[min_index], data[current_index]);
			current_index = min_index;
		}
	}
	return root;
}



#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_ */
