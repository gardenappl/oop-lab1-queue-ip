#include "address_factory.h"
#include "ipv4_address.h"
#include "ipv6_address.h"
#include <stdexcept>
#include <sstream>
#include <limits>

ip_address* address_factory::parse_address(const std::string& str, std::stringstream& str_stream)
{
	//Parse IPv4
	if (str.find(':') == std::string::npos)
	{
		std::cout << "Parsing IPv4...\n";
		ipv4_address* address = new ipv4_address();
		for (int i = 0; i < 4; i++)
		{
			unsigned int temp; //I can't read into uint8_t because that gets interpreted as char
			str_stream >> temp;
			if (temp > std::numeric_limits<uint8_t>::max())
				throw std::invalid_argument("Value can't be more than 255.");
			address->data[i] = temp;

			if (i != 3 && str_stream.get() != '.')
				throw std::invalid_argument("Expected .");
		}
		return address;
	}
	//Parse IPv6
	else
	{
		std::cout << "Parsing IPv6...\n";
		ipv6_address* address = new ipv6_address();
		for (int i = 0; i < 8; i++)
		{
			str_stream >> std::hex >> address->data[i];

			if (i != 7 && str_stream.get() != ':')
				throw std::invalid_argument("Expected :");
		}
		return address;
	}
}

ip_address* address_factory::parse_address(const std::string& str)
{
	std::stringstream str_stream = std::stringstream(str);
	return parse_address(str, str_stream);
}

ip_address* address_factory::parse_subnetwork_address(const std::string& str)
{
	std::stringstream str_stream = std::stringstream(str);
	ip_address* address = address_factory::parse_address(str, str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");

	unsigned int temp;
	str_stream >> std::dec >> temp;
	address->subnet_bits = temp;
	return address;
}

ipv6_address address_factory::local_ipv6_from_mac_auto(const mac_address &mac)
{
    uint16_t address_data[8];
    //prefix for auto-configured addresses
    address_data[0] = 0xFE80u;
    address_data[1] = 0;
    address_data[2] = 0;
    address_data[3] = 0;
    //EUI-64
    address_data[4] = ((uint16_t)mac.data[0] << 8u) + mac.data[1];
    address_data[5] = ((uint16_t)mac.data[2] << 8u) + 0xFF;
    address_data[6] = (0xFEu << 8u) + mac.data[3];
    address_data[7] = ((uint16_t)mac.data[4] << 8u) + mac.data[5];

    //flip the "universal/local" bit of the EUI-64
    address_data[4] ^= 1u << 9;
    return ipv6_address(address_data);
}