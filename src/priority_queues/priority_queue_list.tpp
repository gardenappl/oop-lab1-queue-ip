#pragma once

template<typename T>
priority_queue_list<T>::priority_queue_list(comparator<T>& sort_comparator)
	: priority_queue<T>(sort_comparator)
{}

template<typename T>
priority_queue_list<T>::~priority_queue_list() {
	list_node<T>* current = root;

	while(current) {
		list_node<T>* node_to_remove = current;
		current = current->next;
		delete node_to_remove;
	}
}

template<typename T>
void priority_queue_list<T>::add(const T& element) {
	list_node<T>** current = &root;

	while(*current) {
		if(this->sort_comparator((*current)->value, element)) {
			*current = new list_node<T>(element, *current);
			return;
		} else {
			current = &(*current)->next;
		}
	}

	*current = new list_node<T>(element, *current);
}

template<typename T>
T priority_queue_list<T>::pop() {
	if(!root)
		throw std::out_of_range("tried to pop empty stack");

	T element = root->value;

	list_node<T>* node_to_remove = root;
	root = root->next;
	delete node_to_remove;

	return element;
}

template<typename T>
const T& priority_queue_list<T>::peek() const {
	if(!root)
		throw std::out_of_range("Tried to peek into empty stack");
	return root->value;
}

template<typename T>
void priority_queue_list<T>::print(std::ostream& os) const {
	if(!root) {
		os << "<empty>";
		return;
	}

	os << "{ " << root->value;

	list_node<T>* current = root->next;

	while(current) {
		os << ", " << current->value;
		current = current->next;
	}
	os << " }";
}
