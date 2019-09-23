#include <iostream>
#include "priorityqueuelist.h"

int main(int argc, char **argv) {
	priority_queue<int>* test_list = new priority_queue_list<int>();

	test_list->add(5);
	test_list->add(2);
	test_list->add(7);
	test_list->add(9);
	test_list->add(-2);

	std::cout << *test_list << std::endl;

	std::cout << "Pop: " << test_list->pop() << std::endl;
	std::cout << "Peek: " << *test_list->peek() << std::endl;

	std::cout << *test_list << std::endl;

	return 0;

}
