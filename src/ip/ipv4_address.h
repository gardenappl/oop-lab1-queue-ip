#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"

/*!
 * An IPv4 address, containing 32 bits of data.
 */
struct ipv4_address : public ip_address
{
	/*!
	 * The 32 bits of the address, represented as 4 bytes.
	 */
	std::uint8_t data[4];

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
	/*!
	 * Check if the address belongs to a subnetwork.
	 * \param subnet_address the subnetwork address, including a subnet mask
	 * \return true if this address belongs to the subnetwork, false otherwise
	 */
	bool belongs_to_subnet(const ipv4_address& subnet_address) const;
private:
	/*!
	 * Prints a text representation of the IPv4 address into the output stream.
	 * This method is invoked by the << operator.
	 * \param os the text output stream
	 */
	void print(std::ostream& os) const override;
};
