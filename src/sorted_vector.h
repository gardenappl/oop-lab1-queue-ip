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
	/*!
	 * Constructs a standard sorted vector.
	 */
	sorted_vector();
	/*!
	 * Constructs a sorted vector, which sorts values using the specified comparator function.
	 */
	explicit sorted_vector(comparator<T> comparator);

	/*!
	 * Insert an element into the vector at an appropriate position.
	 * @param element the element to be inserted
	 * @return the index of the element
	 */
	size_t insert(const T& element);

	/*!
	 * Returns the number of elements stored in the vector.
	 * @return the number of elements
	 */
	size_t get_size() const;
	/*!
	 * Removes the last element from the array and returns its value.
	 * @return the removed value
	 */
	T pop_back();
	/*!
	 * Read-only access to the element by its index in the array.
	 * @param index the index
	 * @return the element associated with the index
	 */
	const T& operator[](std::size_t index) const;
};

#include "sorted_vector.tpp"
