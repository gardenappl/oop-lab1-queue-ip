#pragma once

#include "priority_queue.h"
#include "comparator.h"
#include <vector>
#include <algorithm>

/*!
 * A priority queue implemented using a min-heap.
 */
template<typename T>
class priority_queue_heap : public priority_queue<T>
{
private:
	/*!
	 * The array which contains the elements of the min-heap.
	 * \sa get_parent_index(size_t index) const;
	 * \sa get_left_child_index(size_t index) const;
	 * \sa get_right_child_index(size_t index) const;
	 */
	std::vector<T> data;

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
	/*!
	 * Get the index of the parent node.
	 * \param index the index of a child node
	 * \return the parent's index in the data array
	 */
	size_t get_parent_index(size_t index) const;
	/*!
	 * Get the index of the left child node.
	 * Note that this doesn't actually check whether or not a left child node exists,
	 * this method only returns the index of where the child should be.
	 * \param index the index of a parent node
	 * \return the left child's index in the data array.
	 */
	size_t get_left_child_index(size_t index) const;
	/*!
	 * Get the index of the right child node.
	 * Note that this doesn't actually check whether or not a right child node exists,
	 * this method only returns the index of where the child should be.
	 * \param index the index of a parent node
	 * \return the right child's index in the data array.
	 */
	size_t get_right_child_index(size_t index) const;

	/*!
	 * Prints all the elements in the queue into the output stream in the format "{ element1, element2, ... }"
	 * The order of printed elements is based on their priority, starting from the highest priority.
	 * If the queue is empty, prints "<empty>"
	 * This method should be invoked by the << operator.
	 * \param os the output stream
	 */
	void print(std::ostream& os) const;
};

#include "priority_queue_heap.tpp"
