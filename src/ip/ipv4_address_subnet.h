#pragma once

#include "ipv4_address.h"

/*!
 * A struct for working with IPv4 subnetwork address ranges.
 */
struct ipv4_address_subnet
{
	/*!
	 * The subnetwork's underlying IPv4 address.
	 */
	ipv4_address address;

	/*!
	 * The subnetwork allocated bits (in CIDR notation).
	 */
	uint8_t subnet_bits;

	/*!
	 * Create an IPv4 subnet address using 4 bytes and the amount of subnet bits.
	 * \param num1, num2, num3, num4 the bytes
	 * \param subnet_bits the amount of subnet bits
	 */
	ipv4_address_subnet(uint8_t num1, uint8_t num2, uint8_t num3,
		uint8_t num4, uint8_t subnet_bits);


	/*!
	 * Create an IPv4 subnet address using 4 bytes and the amount of subnet bits.
	 * \param address the IPv4 address
	 * \param subnet_bits the amount of subnet bits
	 */
	ipv4_address_subnet(ipv4_address address, uint8_t subnet_bits);

	/*!
	 * Check if the address belongs to a subnetwork.
	 * \param address the address
	 * \return true if the address belongs to this subnetwork, false otherwise
	 */
	bool belongs_to_subnet(const ipv4_address& subnet_address) const;
};


/*!
 * Print the subnetwork info in CIDR notation.
 * \param os the output stream
 * \param address the address
 * \return the output stream
 */
std::ostream& operator<<(std::ostream& os, const ipv4_address_subnet& address);
