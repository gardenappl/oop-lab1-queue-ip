#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

template<typename T>
struct vector
{
private:
	const int min_capacity = 2;

	T* data = new T[min_capacity];
	size_t size = 0;
	size_t capacity = min_capacity;

	void resize_if_needed();
	void resize_and_copy(int new_capacity);

public:
	virtual ~vector();

	size_t get_size() const;
	void resize(size_t new_size);

	size_t push_back(const T& element);
	T pop_back();

	T& operator[](std::size_t index) const;
	T* get_pointer(std::size_t index) const;
};

#include "vector.hpp"


#endif /* VECTOR_H_ */