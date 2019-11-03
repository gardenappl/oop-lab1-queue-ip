#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"

/*!
 * An IPv6 address, containing 128 bits of data and (optionally) a subnet mask.
 */
struct ipv6_address : public ip_address
{
    /*!
     * The 128 bits of the address, represented as 16-bit unsigned ints.
     */
    std::uint16_t data[8];

    /*!
     * Create an IPv6 address from 8 16-bit unsigned integers.
     * \param data the integers
     */
	ipv6_address(uint16_t data[8]);

    /*!
     * Create an all-zero IPv6 address.
     */
	ipv6_address() = default;

	bool operator<(const ipv6_address& address2) const;
	/*!
	 * Prints the IPv6 address in the canonical format.
	 * @param os the output stream
	 */
	void print(std::ostream& os) const override;
    /*!
     * Check if the address belongs to a subnetwork.
     * @param subnet_address the subnetwork address, including a subnet mask
     * \return true if this address belongs to the subnetwork, false otherwise
     */
	bool belongs_to_subnet(const ipv6_address& subnet_address) const;
};