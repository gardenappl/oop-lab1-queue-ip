#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_

#include "priority_queue.h"
#include "../algorithms.h"
#include "../vector.h"
#include <algorithm>


template<typename T>
class priority_queue_heap : public priority_queue<T>
{
private:
	vector<element_with_priority<T>> data;

public:
	void add(T element, int priority);
	T pop();
	const T* peek();

private:
	size_t get_parent_index(size_t index) const;
	size_t get_left_child_index(size_t index) const;
	size_t get_right_child_index(size_t index) const;

	void print(std::ostream& os) const;
};

#include "priority_queue_heap.hpp"

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_ */
