#pragma once

#include <vector>
#include "algorithms.h"
#include "sorted_vector.h"
#include "priority_queue.h"

/*!
 * A priority queue implementation using a resizeable array.
 * \sa array
 * \tparam T type of the stored elements
 */
template<typename T>
class priority_queue_array : public priority_queue<T>
{
	//A sorted vector might be a useful class to have on its own,
	//so we implement it separately.
	sorted_vector<T> sorted_data;

public:
    /*!
     * \copydoc priority_queue::priority_queue(comparator<T>&)
     */
	explicit priority_queue_array(comparator<T>& comparator);

	~priority_queue_array() = default;
    /*!
     * \copydoc priority_queue::add(const T& element)
     */
	void add(const T& element) override;
    /*!
     * \copydoc priority_queue::pop()
     */
	T pop() override;
    /*!
     * \copydoc priority_queue::peek()
     */
    const T& peek() const override;

private:
	void print(std::ostream& os) const override;
};

#include "priority_queue_array.tpp"
