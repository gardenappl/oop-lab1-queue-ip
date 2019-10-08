#pragma once

#include <functional>

template<typename T>
using comparator = std::function<bool(const T&, const T&)>;

template<typename T>
comparator<T> standard_comparator = [](const T& element1, const T& element2) -> bool
{
	return element1 < element2;
};

template<typename T>
struct element_with_priority
{
	T element;
	int priority;

	element_with_priority()
		: priority(0)
	{}

	element_with_priority(T& element, int priority)
		: element(element), priority(priority)
	{}
};

template<typename T>
comparator<element_with_priority<T>> priority_comparator =
		[](const element_with_priority<T> & element1,
		const element_with_priority<T> & element2) -> bool
{
	return element1.priority < element2.priority;
};
