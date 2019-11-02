#pragma once

#include <iostream>
#include <exception>

#include "priority_queue.h"

template<typename T>
struct list_node
{
	list_node* next;
	T value;

	list_node(T value, list_node* next = nullptr)
	: value(value), next(next)
	{}

};

template<typename T>
struct priority_queue_list : public priority_queue<T>{

private:
	list_node<T>* root = nullptr;

public:
    /*!
     * \copydoc priority_queue::priority_queue(comparator<T>&)
     */
    explicit priority_queue_list(comparator<T>& comparator);
	~priority_queue_list();

    /*!
     * \copydoc priority_queue::add(const T& element)
     */
	void add(const T& element) override;
    /*!
     * \copydoc priority_queue:pop()
     */
	T pop() override;
    /*!
     * \copydoc priority_queue::peek()
     */
	const T& peek() const override;

private:
	void print(std::ostream& os) const override;
};

#include "priority_queue_list.tpp"
