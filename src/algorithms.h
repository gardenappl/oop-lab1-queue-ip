#pragma once

#include <functional>
#include <iostream>

/*!
 * A generic function type which is used to compare two elements.
 * \return true if the first argument is less than the second
 * \tparam T the type of the element to compare
 */
template<typename T>
using comparator = std::function<bool(const T&, const T&)>;

/*!
 * A comparator which calls the standard C++ < operator.
 * \return true if the first argument is less than the second
 * \tparam T the type of the element to compare
 */
template<typename T>
comparator<T> standard_comparator = [](const T& element1, const T& element2) -> bool
{
	return element1 < element2;
};