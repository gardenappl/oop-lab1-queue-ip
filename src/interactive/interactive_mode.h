#pragma once

#include "priority_queues/priority_queue.h"
#include "ip/ipv6_address.h"
#include <memory>
#include <iostream>

/*!
 * A class used for running the Interactive Mode
 * and storing relevant run-time information.
 */
class interactive_mode {
private:
	/*!
	 * The queue of elements we're currently working with.
	 */
	std::unique_ptr<priority_queue<ipv6_address>> queue;

public:
	/*!
	 * Enter interactive mode.
	 * \param out a text output stream for interactions
	 * \param in a text input stream for interactions
	 */
	void run(std::ostream& out, std::istream& in);

private:
	/*!
	 * Prints available commands.
	 * \param out the output text stream
	 */
	void print_help(std::ostream& out);
	/*!
	 * Pushes an IPv6 address into the queue.
	 * Prompts the user to either enter an IP address or to generate a random address.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void push_command(std::ostream& out, std::istream& in);
	/*!
	 * Deletes the queue and creates a new one. The user chooses which implementation of the queue to use.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void create_queue_command(std::ostream& out, std::istream& in);
	/*!
	 * Prompts the user to input a MAC address and outputs an IPv6 address based on it.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void ipv6_from_mac_command(std::ostream& out, std::istream& in);
	/*!
	 * Prompts the user to input an IP address and a subnetwork address range.
	 * Then tells the user whether or not the address belongs to the subnetwork
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void check_subnet_command(std::ostream& out, std::istream& in);
	/*!
	 * Prints a random IPv6 address.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void random_ipv6_command(std::ostream& out, std::istream& in);
	/*!
	 * Prints a random IPv4 address.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void random_ipv4_command(std::ostream& out, std::istream& in);
	/*!
	 * Prints a random MAC address.
	 * \param out the output text stream
	 * \param in the input text stream
	 */
	void random_mac_command(std::ostream& out, std::istream& in);
	/*!
	 * Asks the user whether or not to push an IPv6 address onto the current queue
	 * \param address an IPv6 address
	 * \param out the output text stream
	 * \param in the input text stream
	 * \return true if the address was pushed
	 */
	bool ask_to_push(const ipv6_address& address, std::ostream& out, std::istream& in);
};