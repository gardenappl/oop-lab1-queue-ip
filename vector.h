#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

template<typename T>
struct vector
{
protected:
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

	virtual size_t insert(T&& element);
	T pop();

	T& operator[](std::size_t index) const;
	T* get_pointer(std::size_t index) const;

	void print(std::ostream& os) const;
};

#include "vector.hpp"


#endif /* VECTOR_H_ */
