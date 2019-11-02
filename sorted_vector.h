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
    explicit sorted_vector(comparator<T> comparator);

	size_t insert(const T& element);

	size_t get_size() const;
	T pop();

	const T& operator[](std::size_t index) const;
};

#include "sorted_vector.tpp"
