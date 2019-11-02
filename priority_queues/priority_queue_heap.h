#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_

#include "priority_queue.h"
#include "../algorithms.h"
#include "../vector.h"
#include <algorithm>

/*!
 * A priority queue implemented using a max-heap.
 * @sa priority_queue
 */
template<typename T>
class priority_queue_heap : public priority_queue<T>
{
private:
	vector<T> data;

public:
    priority_queue_heap() = default;
    explicit priority_queue_heap(comparator<T>& sort_comparator);

    void add(const T& element) override;
	T pop() override;
	const T& peek() const;

private:
	size_t get_parent_index(size_t index) const;
	size_t get_left_child_index(size_t index) const;
	size_t get_right_child_index(size_t index) const;

	void print(std::ostream& os) const;
};

#include "priority_queue_heap.tpp"

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_ */
