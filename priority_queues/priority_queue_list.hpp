#pragma once

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
const T* priority_queue_list<T>::peek() {
	if(!root)
		throw new std::out_of_range("tried to peek into empty stack");
	return &root->value;
}

template<typename T>
void priority_queue_list<T>::print(std::ostream& os) const {
	if(!root) {
		os << "<empty>";
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
