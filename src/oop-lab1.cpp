#include <iostream>

#include <cassert>
#include <string>
#include <memory>
#include "priority_queues/priority_queue.h"
#include "priority_queues/priority_queue_array.h"
#include "priority_queues/priority_queue_tree.h"
#include "priority_queues/priority_queue_heap.h"
#include "priority_queues/priority_queue_list.h"
#include "interactive/interactive_mode.h"

int main(int argc, char **argv)
{
	std::unique_ptr<priority_queue<int>> int_queues[4];
	int_queues[0] = std::make_unique<priority_queue_array<int>>();
	int_queues[1] = std::make_unique<priority_queue_list<int>>();
	int_queues[2] = std::make_unique<priority_queue_heap<int>>();
	int_queues[3] = std::make_unique<priority_queue_tree<int>>();

	for(auto& queue : int_queues)
	{
		queue->add(5);
		queue->add(2);
		queue->add(8);
		queue->add(1);
		assert(queue->peek() == 8);
		assert(queue->pop() == 8);
		assert(queue->peek() == 5);
		queue->add(10);
		assert(queue->peek() == 10);
	}


	std::unique_ptr<priority_queue<std::string>> string_queues[4];
	string_queues[0] = std::make_unique<priority_queue_heap<std::string>>();
	string_queues[1] = std::make_unique<priority_queue_array<std::string>>();
	string_queues[2] = std::make_unique<priority_queue_list<std::string>>();
	string_queues[3] = std::make_unique<priority_queue_tree<std::string>>();

	int i = 0;
	for(auto& queue : string_queues)
	{
		queue->add("Hell");
		queue->add("Hello");
		//std::cout << *queue << std::endl;
		assert(queue->pop() == "Hello");
		queue->add("Zzzz");
		assert(queue->pop() == "Zzzz");
		assert(queue->pop() == "Hell");
		//std::cout << "tested" << std::endl;
	}


	std::cout << "Tests passed.\n";

	auto interactive = std::make_unique<interactive_mode>();
	interactive->run(std::cout, std::cin);
	std::cout << "Quitting...\n";

	return 0;
}
