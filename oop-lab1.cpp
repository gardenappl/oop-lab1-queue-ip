#include <iostream>

#include "priority_queues/priority_queue_array.h"
#include "priority_queues/priority_queue_list.h"
#include "priority_queues/priority_queue_heap.h"

#include "ip/ipv4_address.h"
#include "ip/ipv6_address.h"
#include "ip/ip_address.h"
#include "ip/ip_factory.h"

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


	test_list->add(9, 9);
	test_list->add(5, 5);
	test_list->add(2, 2);
	test_list->add(7, 7);
	test_list->add(-2, 999);

	std::cout << *test_list << std::endl;

//	std::cout << "Pop: " << test_list->pop() << std::endl;
	std::cout << "Peek: " << *test_list->peek() << std::endl;

	std::cout << *test_list << std::endl;

	delete test_list;


	ipv4_address address(1, 2, 3, 4);
	std::cout << address << std::endl;

	ipv4_address subnet_address(1, 2, 3, 4);
	subnet_address.subnet_bits = 4;
	std::cout << std::boolalpha << address.belongs_to_subnet(subnet_address) << std::endl;

	address.data[3] = 3;
	std::cout << address << std::endl;
	std::cout << std::boolalpha << address.belongs_to_subnet(subnet_address) << std::endl;

	address.data[0] = 3;
	std::cout << address << std::endl;
	std::cout << std::boolalpha << address.belongs_to_subnet(subnet_address) << std::endl;

	ip_address* address2 = ip_factory::parse_address("4.2.3.1");
	std::cout << *address2 << std::endl;
	delete address2;

	uint16_t data[8];
	data[0] = 0;
	data[1] = 1234;
	data[2] = 500;
	data[3] = 12;
	data[4] = 152;
	data[5] = 65535;
	data[6] = 0;
	data[7] = 128;
	ipv6_address address3(data);
	std::cout << address3 << std::endl;

	address2 = ip_factory::parse_subnetwork_address("f431:0:abcd:1111:ffff:0000:1234:0001/25");
	std::cout << *address2 << std::endl;
	delete address2;

	priority_queue_heap<ipv4_address> ip_queue;
	ip_queue.add(ipv4_address(1, 2, 3, 4), 1);
	ip_queue.add(ipv4_address(4, 3, 2, 1), 2);
	ip_queue.add(ipv4_address(9, 9, 9, 9), 3);

	std::cout << ip_queue << std::endl;
	ip_queue.pop();
	std::cout << ip_queue << std::endl;
	ip_queue.pop();
	std::cout << ip_queue << std::endl;


	return 0;

}
