#pragma once

#include "ip_address.h"
#include "ipv6_address.h"
#include "mac_address.h"
#include <string>
#include <sstream>

/*!
 * A static class for creating network addreses of various types.
 */
class address_factory
{
private:
	static ip_address* parse_address(const std::string& str, std::stringstream& str_stream);

public:
    /*!
     * Creates a link-local IPv6 addresss fot a given MAC address. Used for stateless address autoconfiguration.
     * \param mac the MAC address
     * \return an IPv6 address
     */
    static ipv6_address local_ipv6_from_mac_auto(const mac_address& mac);

    /*!
     * Parses an IP address from a string.
     * \param str a string in standard notation
     * \return either an IPv4 address or an IPv6 address.
     * \throws std::invalid_exception if the address string is in invalid format
     */
	static ip_address* parse_address(const std::string& str);

    /*!
     * Parses an IP subnetwork range from a string.
     * \param str a string in CIDR notation
     * \return either an IPv4 or IPv6 subnetwork address with subnet mask
     * \throws std::invalid_exception if the address string is in invalid format
     */
	static ip_address* parse_subnetwork_address(const std::string& str);
};
