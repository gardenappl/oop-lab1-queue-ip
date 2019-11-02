#pragma once

#include <vector>
#include "algorithms.h"
#include "sorted_vector.h"
#include "priority_queue.h"

template<typename T>
class priority_queue_array : public priority_queue<T>
{
	//A sorted vector might be a useful class to have on its own,
	//so we implement it separately.
	sorted_vector<T> sorted_data;

public:
	priority_queue_array() = default;
	explicit priority_queue_array(comparator<T>& comparator);

	~priority_queue_array() = default;
	void add(const T& element) override;
	T pop() override;
    const T& peek() const override;
	void print(std::ostream& os) const override;
};

#include "priority_queue_array.tpp"
