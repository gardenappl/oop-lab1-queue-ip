#pragma once

#include <iostream>
#include <exception>

#include "priority_queue.h"

/*!
 * A structure which represents a node in a linked list.
 * \tparam T the type of element stored in the linked list
 */
template<typename T>
struct list_node
{
	/*!
	 * A pointer to the next node in a linked list.
	 * If this is the last element in the list, the value is nullptr
	 */
	list_node* next;
	/*!
	 * The value of the element stored in this node.
	 */
	T value;

	/*!
	 * Construct a node.
	 * \param value the value of the element stored in this node
	 * \param next (optional) a pointer to the next node in a linked list
	 */
	list_node(T value, list_node* next = nullptr)
	: value(value), next(next)
	{}

};

/*!
 * A priority queue implementation using a linked list.
 * \sa array
 * \tparam T type of the stored elements
 */
template<typename T>
struct priority_queue_list : public priority_queue<T>{

private:
	/*!
	 * The first element in the linked list.
	 * If the list is empty, this value is set to nullptr.
	 */
	list_node<T>* root = nullptr;

public:
	/*!
	 * \copydoc priority_queue::priority_queue()
	 */
	priority_queue_list() = default;
	/*!
	 * \copydoc priority_queue<T>::priority_queue(comparator<T>&)
	 */
	explicit priority_queue_list(comparator<T>& comparator);
	~priority_queue_list();

	/*!
	 * \copydoc priority_queue<T>::add(const T& element)
	 * \details The linked-list-based implementation of this function operates in O(n) time.
	 */
	void add(const T& element) override;
	/*!
	 * \copydoc priority_queue<T>:pop()
	 * \details The linked-list-based implementation of this function operates in O(1) time.
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

#include "priority_queue_list.tpp"
