#pragma once

#include <cstdint>
#include <iostream>

struct mac_address {
	/*!
	 * The octets of the MAC address.
	 */
	std::uint8_t data[6];

	/*!
	 * Create a MAC address using 6 octets.
	 * \param data octets
	 */
	mac_address(std::uint8_t data[6]);
	/*!
	 * Create a MAC address 00-00-00-00-00-00
	 */
	mac_address() = default;
};

/*!
 * Prints a text representation of the MAC address into the output stream.
 * \param os the text output stream
 * \param address the MAC address
 * \return the output stream after the MAC address has been printed
 */
std::ostream& operator<<(std::ostream& os, const mac_address& address);
