#pragma once

#include <vector>
#include "algorithms.h"
#include "sorted_vector.h"
#include "priority_queue.h"

/*!
 * A priority queue implementation using a resizeable array.
 * \sa vector
 * \sa sorted_vector
 * \tparam T type of the stored elements
 */
template<typename T>
class priority_queue_array : public priority_queue<T>
{
	/*!
	 * The data that's stored in the array, automatically sorted as new elements are added into it.
	 * \sa sorted_vector<T>
	 */
	sorted_vector<T> sorted_data;

public:
	/*!
	 * \copydoc priority_queue::priority_queue()
	 */
	priority_queue_array() = default;
	/*!
	 * \copydoc priority_queue::priority_queue(comparator<T>&)
	 */
	explicit priority_queue_array(comparator<T>& comparator);

	~priority_queue_array() = default;
	/*!
	 * \copydoc priority_queue::add(const T& element)
	 * \details The array-based implementation of this function works in O(n) time,
	 * possibly resizing the array and invalidating pointers.
	 */
	void add(const T& element) override;
	/*!
	 * \copydoc priority_queue::pop()
	 * \details The array-based implementation of this function works in O(1) time.
	 */
	T pop() override;
	/*!
	 * \copydoc priority_queue::peek()
	 */
	const T& peek() const override;

private:
	/*!
	 * Prints all the elements in the queue into the output stream in the format "{ element1, element2, ... }"
	 * The order of printed elements is based on their priority, starting from the highest priority.
	 * If the queue is empty, prints "<empty>"
	 * This method should be invoked by the << operator.
	 * \param os the output stream
	 */
	void print(std::ostream& os) const override;
};

#include "priority_queue_array.tpp"
