#include <iostream>
#include "priority_queues/priorityqueuelist.h"
#include "priority_queues/priorityqueuearray.h"

int main(int argc, char **argv) {
	std::cout << "Hello" << std::endl;
	sorted_vector<int> vector;

	vector.insert(99);
	vector.insert(5);
	vector.insert(999);
	vector.insert(3);
	vector.insert(1);
	vector.insert(7);

	for(std::size_t i = 0; i < vector.get_size(); i++)
	{
		std::cout << vector[i] << ", ";
	}

	priority_queue<int>* test_list = new priority_queue_array<int>();


	test_list->add(5, 5);
	test_list->add(2, 2);
	test_list->add(7, 7);
	test_list->add(9, 9);
	test_list->add(-2, 999);

	std::cout << *test_list << std::endl;

	std::cout << "Pop: " << test_list->pop() << std::endl;
	std::cout << "Peek: " << *test_list->peek() << std::endl;

	std::cout << *test_list << std::endl;

	delete test_list;

	return 0;

}
