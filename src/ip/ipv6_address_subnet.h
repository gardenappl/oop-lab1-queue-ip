#pragma once

#include "ipv6_address.h"

/*!
 * A struct for working with IPv4 subnetwork address ranges.
 */
struct ipv6_address_subnet
{
	/*!
	 * The subnetwork's underlying IPv4 address.
	 */
	ipv6_address address;

	/*!
	 * The subnetwork allocated bits (in CIDR notation).
	 */
	uint8_t subnet_bits;

	/*!
	 * Create an IPv6 subnet address using 16 bytes and the amount of subnet bits.
	 * \param data the 16 bytes
	 * \param subnet_bits the amount of subnet bits
	 */
	ipv6_address_subnet(uint8_t data[16], uint8_t subnet_bits);

	/*!
	 * Create an IPv6 subnet address using a pre-existing IPv6 address and the amount of subnet bits.
	 * \param address the subnetwork's address
	 * \param subnet_bits the amount of subnetwork bits
	 */
	ipv6_address_subnet(const ipv6_address& address, uint8_t subnet_bits);
	/*!
	 * Check if the address belongs to this subnetwork.
	 * \param address2 the address
	 * \return true if this address belongs to the subnetwork, false otherwise
	 */
	bool belongs_to_subnet(const ipv6_address& address2) const;
};

/*!
 * Print the subnetwork info in CIDR notation.
 * \param os the output stream
 * \param address the address
 * \return the output stream
 */
std::ostream& operator<<(std::ostream& os, const ipv6_address_subnet& address);