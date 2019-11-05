#pragma once

#include <random>
#include "ip_address.h"
#include "ipv6_address.h"
#include "mac_address.h"
#include "ipv4_address.h"
#include <string>
#include <sstream>

/*!
 * A static class for creating network addreses of various types.
 */
class address_factory
{
private:
	static ipv4_address parse_ipv4_address(std::stringstream& str_stream);
	static ipv6_address parse_ipv6_address(const std::string& str, std::stringstream& str_stream);


public:
	/*!
	 * Create a random MAC address.
	 * \return a random address
	 */
	static mac_address random_mac_address();

	/*!
	 * Create a random IPv4 address.
	 * \return a random address
	 */
	static ipv4_address random_ipv4_address();
	/*!
	 * Create a random IPv6 address.
	 * \return a random address
	 */
	static ipv6_address random_ipv6_address();

	/*!
	 * Creates a link-local IPv6 addresss fot a given MAC address. Used for stateless address autoconfiguration.
	 * \param mac the MAC address
	 * \return an IPv6 address
	 */
	static ipv6_address local_ipv6_from_mac_auto(const mac_address& mac);

	/*!
	 * Parses an IPv4 address from a string.
	 * \param str a string in standard notation
	 * \return an IPv4 address.
	 * \throws std::invalid_exception if the address string is in invalid format
	 */
	static ipv4_address parse_address_as_ipv4(const std::string& str);

	/*!
	 * Parses an IPv6 address from a string. If the string represents an IPv4 address,
	 * performs a conversion.
	 * \param str a string in standard notation
	 * \return an IPv6 address.
	 * \throws std::invalid_exception if the address string is in invalid format
	 */
	static ipv6_address parse_address_as_ipv6(const std::string& str);

	/*!
	 * Parses an IPv4 subnetwork range from a string.
	 * \param str a string in CIDR notation
	 * \return an IPv4 subnetwork address with subnet mask
	 * \throws std::invalid_exception if the address string is in invalid format
	 */
	static ipv4_address parse_subnet_address_as_ipv4(const std::string& str);

	/*!
	 * Parses an IPv6 subnetwork range from a string. If the string represents an IPv4 address,
	 * performs a conversion.
	 * \param str a string in CIDR notation
	 * \return an IPv6 subnetwork address with subnet mask
	 * \throws std::invalid_exception if the address string is in invalid format
	 */
	static ipv6_address parse_subnet_address_as_ipv6(const std::string& str);

	/*!
	 * Parses a MAC address from a string.
	 * \param str a string in standard notation
	 * \return a MAC address.
	 * \throws std::invalid_exception if the address string is in invalid format
	 */
	static mac_address parse_mac_address(const std::string& str);
};
