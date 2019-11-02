#pragma once

#include "algorithms.h"
#include "vector.h"


template<typename T>
struct sorted_vector
{
private:
    vector<T> data_vector;
	comparator<T> sort_comparator;

public:
	sorted_vector();
	sorted_vector(comparator<T> comparator);

	size_t insert(const T& element);

	size_t get_size() const;
	T pop();

	const T& operator[](std::size_t index) const;
	const T* get_pointer(std::size_t index) const;

	friend std::ostream& operator<<(std::ostream& os, sorted_vector vec);
};

#include "sorted_vector.hpp"
