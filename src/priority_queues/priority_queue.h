#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_H_

#include "algorithms.h"
#include <iostream>

/*!
 * A priority queue is a container adaptor that provides constant time lookup of the largest
 * (by default) element, at the expense of slower insertion and/or extraction.
 * \tparam T type of the stored elements
 */
template<typename T>
struct priority_queue {
protected:
	comparator<T> sort_comparator;

public:
	/*!
	 * Constructs a priority queue with default behaviour.
	 */
	priority_queue();
	/*!
	 * Constructs a priority queue with a custom comparator function.
	 * The function will be used to sort priorities of elements.
	 * \param sort_comparator the comparator function to use for sorting priorities
	 */
	explicit priority_queue(comparator<T>& sort_comparator);
	virtual ~priority_queue() = default;

	/*!
	 * Insert an element into the priority queue.
	 * \param element the element to be inserted
	 */
	virtual void add(const T& element) = 0;

	/*!
	 * Remove the highest-priority element and return its value.
	 * \return the element with the highest priority value
	 */
	virtual T pop() = 0;
	/*!
	 * Return a reference to the highest-priority element. This is an O(1) operation.
	 * Keep in mind that the reference might be invalidated after modifying the queue.
	 * \return the element with the highest priority value
	 */
	virtual const T& peek() const = 0;

private:
	virtual void print(std::ostream& os) const = 0;


	friend std::ostream& operator<<(std::ostream& os, const priority_queue<T>& queue) {
		queue.print(os);
		return os;
	}
};

template<typename T>
priority_queue<T>::priority_queue()
	: sort_comparator(standard_comparator<T>)
{}

template<typename T>
priority_queue<T>::priority_queue(comparator<T>& sort_comparator)
	: sort_comparator(sort_comparator)
{}

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_H_ */
