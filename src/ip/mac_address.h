#ifndef OOP_LAB1_MAC_ADDRESS_H
#define OOP_LAB1_MAC_ADDRESS_H

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

std::ostream& operator<<(std::ostream& os, const mac_address& address);


#endif //OOP_LAB1_MAC_ADDRESS_H
