#pragma once

#include "ip_factory.h"
#include "ipv4_address.h"
#include "ipv6_address.h"
#include <stdexcept>
#include <sstream>
#include <limits>

ip_address* ip_factory::parse_address(const std::string& str, std::stringstream& str_stream)
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
			if (temp > (unsigned int)std::numeric_limits<uint8_t>::max)
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

ip_address* ip_factory::parse_address(const std::string& str)
{
	std::stringstream str_stream = std::stringstream(str);
	return parse_address(str, str_stream);
}

ip_address* ip_factory::parse_subnetwork_address(const std::string& str)
{
	std::stringstream str_stream = std::stringstream(str);
	ip_address* address = ip_factory::parse_address(str, str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");

	unsigned int temp;
	str_stream >> std::dec >> temp;
	address->subnet_bits = temp;
	return address;
}