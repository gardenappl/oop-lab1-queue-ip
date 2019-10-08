#pragma once

#include "algorithms.h"

template<typename T>
struct sorted_vector
{
private:
	const int min_capacity = 2;

	T* data = new T[min_capacity];
	comparator<T> sort_comparator;
	size_t size = 0;
	size_t capacity = min_capacity;

	void resize_if_needed();
	void resize_and_copy(int new_capacity);

public:
	sorted_vector();
	sorted_vector(comparator<T> comparator);
	~sorted_vector();

	size_t get_size() const;

	void insert(T&& element);
	T pop();

	const T& operator[](std::size_t index) const;
	T* get_pointer(std::size_t index) const;
};

#include "sorted_vector.hpp"
