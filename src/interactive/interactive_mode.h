#ifndef OOP_LAB1_INTERACTIVE_MODE_H
#define OOP_LAB1_INTERACTIVE_MODE_H

#include "priority_queues/priority_queue.h"
#include "ip/ipv6_address.h"
#include <memory>
#include <iostream>

class interactive_mode {
private:
	std::unique_ptr<priority_queue<ipv6_address>> queue;

public:
	/*!
	 * Enter interactive mode.
	 * \param out a text output stream for interactions
	 * \param in a text input stream for interactions
	 */
	void run(std::ostream& out, std::istream& in);

private:
	void print_help(std::ostream& out);
	void push_command(std::ostream& out, std::istream& in);
	void create_queue_command(std::ostream& out, std::istream& in);
	void ipv6_from_mac_command(std::ostream& out, std::istream& in);
	void check_subnet_command(std::ostream& out, std::istream& in);
	void random_ipv6_command(std::ostream& out, std::istream& in);
	void random_ipv4_command(std::ostream& out, std::istream& in);
	void random_mac_command(std::ostream& out, std::istream& in);
};


#endif //OOP_LAB1_INTERACTIVE_MODE_H
