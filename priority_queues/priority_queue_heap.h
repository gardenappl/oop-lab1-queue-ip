#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_

#include "priority_queue.h"
#include "../algorithms.h"
#include "../vector.h"
#include <algorithm>

/*!
 * A priority queue implemented using a min-heap.
 * @sa priority_queue
 */
template<typename T>
class priority_queue_heap : public priority_queue<T>
{
private:
	vector<T> data;

public:
    /*!
     * \copydoc priority_queue::priority_queue()
     */
    priority_queue_heap() = default;
    /*!
     * \copydoc priority_queue::priority_queue(comparator<T>&)
     */
    explicit priority_queue_heap(comparator<T>& sort_comparator);

    /*!
     * \copydoc priority_queue::add(const T& element)
     * \details The heap-based implementation of this function operates in O(log n) time.
     */
    void add(const T& element) override;
    /*!
     * \copydoc priority_queue::pop()
     * \details The heap-based implementation of this function operates in O(log n) time.
     */
	T pop() override;
    /*!
     * \copydoc priority_queue::peek()
     */
	const T& peek() const override;

private:
	size_t get_parent_index(size_t index) const;
	size_t get_left_child_index(size_t index) const;
	size_t get_right_child_index(size_t index) const;

	void print(std::ostream& os) const;
};

#include "priority_queue_heap.tpp"

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_HEAP_H_ */
