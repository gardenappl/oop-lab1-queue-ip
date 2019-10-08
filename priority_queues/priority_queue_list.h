#pragma once

#include <iostream>
#include <exception>

#include "priority_queue.h"

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

#include "priority_queue_list.hpp"
