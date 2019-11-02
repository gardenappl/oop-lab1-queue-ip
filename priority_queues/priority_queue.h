#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_H_

#include "algorithms.h"
#include <iostream>

template<typename T>
struct priority_queue {
protected:
    comparator<T> sort_comparator;

public:
    priority_queue();
    explicit priority_queue(comparator<T>& sort_comparator);
	virtual ~priority_queue() = default;

	virtual void add(const T& element) = 0;
	virtual T pop() = 0;
	virtual const T& peek() const = 0;

private:
	virtual void print(std::ostream& os) const = 0;


	friend std::ostream& operator<<(std::ostream& os, const priority_queue<T>& queue) {
		queue.print(os);
		return os;
	}
};

template<typename T>
priority_queue<T>::priority_queue()
    : sort_comparator(standard_comparator<T>)
{}

template<typename T>
priority_queue<T>::priority_queue(comparator<T>& sort_comparator)
    : sort_comparator(sort_comparator)
{}

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_H_ */
