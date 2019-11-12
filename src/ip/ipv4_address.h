#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"

/*!
 * An IPv4 address, containing 32 bits of data.
 */
struct ipv4_address : public ip_address<4>
{
	/*!
	 * Create an IPv4 address using 4 bytes.
	 */
	ipv4_address(uint8_t num1, uint8_t num2, uint8_t num3,
		uint8_t num4);

	/*!
	 * Create the IPv4 address 0.0.0.0
	 */
	ipv4_address() = default;

	/*!
	 * Compare this address to another IPv4 address.
	 * \param address2 another IPv4 address
	 * \return true if this address is "less" than address2 (in lexicographical order)
	 */
	bool operator<(const ipv4_address& address2) const;
};

/*!
 * Prints the IPv4 address in the canonical format.
 * \param os the output stream
 */
std::ostream& operator<<(std::ostream& os, const ipv4_address& address);