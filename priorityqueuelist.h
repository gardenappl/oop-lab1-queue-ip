#ifndef PRIORITYQUEUELIST_H_
#define PRIORITYQUEUELIST_H_

#include "priorityqueue.h"
#include <iostream>
#include <exception>

template<typename T>
struct priority_node
{
	priority_node* next;
	int priority;
	T value;

	priority_node(T value, int priority, priority_node* next = nullptr)
	: value(value), priority(priority), next(next)
	{}

};

template<typename T>
struct priority_queue_list : priority_queue<T>{

private:
	priority_node<T>* root = nullptr;

public:
	~priority_queue_list();
	void add(T element, int priority);
	T pop();
	T* peek();

private:
	void print(std::ostream& os) const;
};

template<typename T>
priority_queue_list<T>::~priority_queue_list() {
	priority_node<T>* current = root;

	while(current) {
		priority_node<T>* node_to_remove = current;
		current = current->next;
		delete node_to_remove;
	}
}

template<typename T>
void priority_queue_list<T>::add(T element, int priority) {
	priority_node<T>** current = &root;

	while(*current) {
		if(priority > (*current)->priority) {
			*current = new priority_node<T>(element, priority, *current);
			return;
		} else {
			current = &(*current)->next;
		}
	}

	*current = new priority_node<T>(element, priority, *current);
}

template<typename T>
T priority_queue_list<T>::pop() {
	if(!root)
		throw new std::out_of_range("tried to pop empty stack");

	T element = root->value;

	priority_node<T>* node_to_remove = root;
	root = root->next;
	delete node_to_remove;

	return element;
}

template<typename T>
T* priority_queue_list<T>::peek() {
	if(!root)
		throw new std::out_of_range("tried to peek into empty stack");
	return &root->value;
}

template<typename T>
void priority_queue_list<T>::print(std::ostream& os) const {
	if(!root) {
		os << "<empty list>";
		return;
	}

	os << "{ " << root->value;

	priority_node<T>* current = root->next;

	while(current) {
		os << ", " << current->value;
		current = current->next;
	}
	os << " }";
}

#endif /* PRIORITYQUEUELIST_H_ */
