#ifndef PRIORITY_QUEUES_PRIORITY_QUEUE_H_
#define PRIORITY_QUEUES_PRIORITY_QUEUE_H_

#include <iostream>

template<typename T>
struct priority_queue {

public:
	virtual ~priority_queue() {}

	virtual void add(T element, int priority) = 0;
	virtual T pop() = 0;
	virtual const T* peek() = 0;

private:
	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const priority_queue<T>& queue) {
		queue.print(os);
		return os;
	}
};

#endif /* PRIORITY_QUEUES_PRIORITY_QUEUE_H_ */
