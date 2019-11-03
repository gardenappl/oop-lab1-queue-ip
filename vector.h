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

	/*!
	 * Get the size of the current vector.
	 * Note that this only returns the amount of elements stored, not the total capacity of the underlying array,
	 * which might be larger than the returned value.
	 * @return number of elements in the vector
	 */
	size_t get_size() const;

	/*!
	 * Inserts an element to the end of the array.
	 * @param element the element to be inserted
	 * @return the index of the inserted element
	 */
	size_t push_back(const T& element);
	/*!
	 * Removes the last element from the array and returns its value.
	 * @return the removed value
	 */
	T pop_back();

	/*!
	 * Access an element by its index in the array.
	 * @param index the index
	 * @return the value associated with the index
	 */
	T& operator[](std::size_t index) const;
};

#include "vector.tpp"


#endif /* VECTOR_H_ */
