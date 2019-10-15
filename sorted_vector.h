#pragma once

#include "algorithms.h"
#include "vector.h"


//Use protected inheritance in order to hide the [] setter operator
//Elements in sorted vector are read-only
template<typename T>
struct sorted_vector : protected vector<T>
{
private:
	comparator<T> sort_comparator;

public:
	sorted_vector();
	sorted_vector(comparator<T> comparator);

	size_t insert(T&& element);

	size_t get_size() const;
	T pop();

	const T& operator[](std::size_t index) const;
	const T* get_pointer(std::size_t index) const;
};

#include "sorted_vector.hpp"
