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

		int parent_index = get_parent_index(index);
		if(data[parent_index].priority > priority)
		{
			std::cout << "Swapping " << data[parent_index].element
					<< " " << data[index].element << std::endl;
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
	return data[0].element;
}



#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_HPP_ */
