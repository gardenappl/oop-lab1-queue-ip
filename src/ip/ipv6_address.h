#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"
#include "ipv4_address.h"

/*!
 * An IPv6 address, containing 128 bits of data and (optionally) a subnet mask.
 */
struct ipv6_address : public ip_address<16>
{
	/*!
	 * Create an IPv6 address from 16 8-bit unsigned integers.
	 * \param data the integers
	 */
	explicit ipv6_address(uint8_t data[16]);

	/*!
	 * Convert an IPv4 address into an IPv6 address.
	 * \param address the IPv4 address
	 */
	ipv6_address(const ipv4_address& address);

	/*!
	 * Create an all-zero IPv6 address.
	 */
	ipv6_address() = default;

	/*!
	 * Compare this address to another IPv6 address.
	 * \param address2 another IPv6 address
	 * \return true if this address is "less" than address2 (in lexicographical order)
	 */
	bool operator<(const ipv6_address& address2) const;
};

/*!
 * Prints the IPv6 address in the canonical format.
 * \param os the output stream
 */
std::ostream& operator<<(std::ostream& os, const ipv6_address& address);