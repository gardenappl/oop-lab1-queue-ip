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
     * The 32 its of the address, represented as 4 bytes.
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

	bool operator<(const ipv4_address& address2) const;
    /*!
     * Check if the address belongs to a subnetwork.
     * @param subnet_address the subnetwork address, including a subnet mask
     * \return true if this address belongs to the subnetwork, false otherwise
     */
	bool belongs_to_subnet(const ipv4_address& subnet_address) const;
private:
    void print(std::ostream& os) const override;
};
