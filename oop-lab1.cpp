#include <iostream>

#include "priority_queues/priority_queue_array.h"
#include "priority_queues/priority_queue_list.h"
#include "priority_queues/priority_queue_heap.h"
#include "priority_queues/priority_queue_tree.h"

#include "ip/ipv4_address.h"
#include "ip/ipv6_address.h"
#include "ip/ip_address.h"
#include "ip/address_factory.h"

int main(int argc, char **argv) {
	std::cout << "Hello" << std::endl;

	priority_queue<int>* test_list = new priority_queue_heap<int>();


	test_list->add(9);
	test_list->add(5);
	test_list->add(2);
	test_list->add(7);
	test_list->add(-2);

	std::cout << *test_list << std::endl;

    std::cout << "Pop: " << test_list->pop() << std::endl;
    std::cout << *test_list << std::endl;

	std::cout << "Peek: " << test_list->peek() << std::endl;

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

	ipv6_address address2 = address_factory::parse_address_as_ipv6("4.2.3.1");
	std::cout << address2 << std::endl;

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

	address3 = address_factory::parse_subnet_address_as_ipv6("f431:0:abcd:1111:ffff:0000:1234:0001/25");
	std::cout << address3 << std::endl;

	priority_queue_heap<ipv4_address> ip_queue;
	ip_queue.add(ipv4_address(1, 2, 3, 4));
	ip_queue.add(ipv4_address(4, 3, 2, 1));
	ip_queue.add(ipv4_address(9, 9, 9, 9));

	uint8_t mac_address_data[6];
	mac_address_data[0] = 1;
	mac_address_data[1] = 10;
	mac_address_data[2] = 255;
	mac_address_data[3] = 0;
	mac_address_data[4] = 16;
	mac_address mac_address1(mac_address_data);
	std::cout << mac_address1 << std::endl;
    std::cout << address_factory::local_ipv6_from_mac_auto(mac_address1) << std::endl;

	std::cout << ip_queue << std::endl;
	ip_queue.pop();
	std::cout << ip_queue << std::endl;
	ip_queue.pop();
	std::cout << ip_queue << std::endl;


	return 0;

}
