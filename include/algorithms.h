#pragma once

#include <functional>
#include <iostream>

template<typename T>
using comparator = std::function<bool(const T&, const T&)>;

template<typename T>
comparator<T> standard_comparator = [](const T& element1, const T& element2) -> bool
{
	return element1 < element2;
};

//template<typename T>
//struct element_with_priority
//{
//	T element;
//	int priority;
//
//	element_with_priority()
//		: priority(0)
//	{}
//
//	element_with_priority(const T& element, int priority)
//		: element(element), priority(priority)
//	{}
//};
//
//template<typename T>
//bool operator<(const element_with_priority<T>& element1,
//		const element_with_priority<T>& element2)
//{
//	return element1.priority < element2.priority;
//}
//
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const element_with_priority<T> element)
//{
//    os << "( " << element.element << ", priority: " << element.priority << " )";
//    return os;
//}