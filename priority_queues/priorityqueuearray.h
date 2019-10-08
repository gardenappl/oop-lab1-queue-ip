#pragma once

#include <vector>
#include "../algorithms.h"
#include "priorityqueue.h"
#include "../sorted_vector.h"

template<typename T>
class priority_queue_array : public priority_queue<T>
{
	//A sorted vector might be a useful class to have on its own,
	//so we implement it separately.
	sorted_vector<element_with_priority<T>> vector;

public:
	priority_queue_array();

	~priority_queue_array() = default;
	void add(T element, int priority);
	T pop();
	T* peek();
	void print(std::ostream& os) const;
};

#include "priorityqueuearray.hpp"
