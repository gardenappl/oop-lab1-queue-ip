#pragma once

#include "algorithms.h"
#include "priority_queue_tree.h"
#include <stdexcept>

template<typename T>
void priority_queue_tree<T>::remove(tree_node<T> *node)
{
	if(node->left)
		remove(node->left);
	if(node->right)
		remove(node->right);
	delete node;
}


template<typename T>
priority_queue_tree<T>::priority_queue_tree(comparator<T>& sort_comparator)
	: priority_queue<T>(sort_comparator)
{}

template<typename T>
priority_queue_tree<T>::~priority_queue_tree()
{
	if(root)
		remove(root);
}

template<typename T>
void priority_queue_tree<T>::add(const T &element)
{
	tree_node<T>** current = &root;

	while(*current != nullptr)
	{
		if(this->sort_comparator(element, (*current)->value))
			current = &((*current)->left);
		else
			current = &((*current)->right);
	}
	*current = new tree_node<T>(element);
}

template<typename T>
T priority_queue_tree<T>::pop()
{
	if(!root)
		throw std::out_of_range("Tried to pop empty stack.");
	tree_node<T>** max_node = &root;
	while((*max_node)->right)
		max_node = &(*max_node)->right;

	T value = (*max_node)->value;

	//only has left child
	if((*max_node)->left)
	{
		tree_node<T>* delete_node = *max_node;
		*max_node = (*max_node)->left;
		delete delete_node;
	}
	//no children
	else
	{
		tree_node<T>* delete_node = *max_node;
		*max_node = nullptr;
		delete delete_node;
	}

	return value;
}

template<typename T>
const T& priority_queue_tree<T>::peek() const
{
	if(!root)
		throw std::out_of_range("Tried to peek into empty stack");
	tree_node<T>* max_node = root;
	while(max_node->right)
		max_node = max_node->right;
	return max_node->value;
}

template<typename T>
void priority_queue_tree<T>::print(std::ostream& os, const tree_node<T>* node, bool& printed_once) const
{
	if(node->right)
	{
		print(os, node->right, printed_once);
		printed_once = true;
	}
	if(printed_once)
		os << ", ";
	os << node->value;
	printed_once = true;
	if(node->left)
	{
		print(os, node->left, printed_once);
	}
}

template<typename T>
void priority_queue_tree<T>::print(std::ostream& os) const
{
	if(!root)
	{
		os << "<empty>";
		return;
	}
	bool printed_once = false;
	os << "{ ";
	print(os, root, printed_once);
	os << " }";
}