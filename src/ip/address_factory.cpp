#include "ip/address_factory.h"
#include "ip/ipv4_address.h"
#include "ip/ipv6_address.h"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <random>

ipv4_address address_factory::random_ipv4_address()
{
	static std::default_random_engine rng;
	static std::uniform_int_distribution<uint8_t> dist(0, std::numeric_limits<uint8_t>::max());
	return ipv4_address(dist(rng), dist(rng), dist(rng), dist(rng));
}

ipv6_address address_factory::random_ipv6_address()
{
	static std::default_random_engine rng;
	static std::uniform_int_distribution<uint16_t> dist(0, std::numeric_limits<uint16_t>::max());
	uint16_t data[8];
	for(size_t i = 0; i < 8; i++)
		data[i] = dist(rng);
	return ipv6_address(data);
}

mac_address address_factory::random_mac_address()
{
	static std::default_random_engine rng;
	static std::uniform_int_distribution<uint8_t> dist(0, std::numeric_limits<uint8_t>::max());
	uint8_t data[6];
	for(size_t i = 0; i < 6; i++)
		data[i] = dist(rng);
	return mac_address(data);
}

ipv4_address address_factory::parse_ipv4_address(std::stringstream& str_stream)
{
	ipv4_address address;
	for (int i = 0; i < 4; i++)
	{
		unsigned int temp; //I can't read into uint8_t because that gets interpreted as char
		str_stream >> temp;
		if (temp > std::numeric_limits<uint8_t>::max())
			throw std::invalid_argument("Value can't be more than 255.");
		address.data[i] = temp;

		if (i != 3 && str_stream.get() != '.')
			throw std::invalid_argument("Expected .");
	}
	return address;
}

ipv6_address address_factory::parse_ipv6_address(const std::string& str, std::stringstream& str_stream)
{
	//Parse IPv4
	if (str.find(':') == std::string::npos)
	{
		return ipv6_address(parse_ipv4_address(str_stream));
	}
	//Parse IPv6
	else
	{
		std::cout << "Parsing IPv6...\n";
		ipv6_address address;
		for (int i = 0; i < 8; i++)
		{
			str_stream >> std::hex >> address.data[i];

			if (i != 7 && str_stream.get() != ':')
				throw std::invalid_argument("Expected :");
		}
		return address;
	}
}

ipv4_address address_factory::parse_address_as_ipv4(const std::string &str)
{
	std::stringstream str_stream(str);
	ipv4_address address = parse_ipv4_address(str_stream);
	char c = str_stream.peek();
	if(c != EOF)
	{
		std::string s("Unexpected character: ");
		s += c;
		throw std::invalid_argument(s);
	}
	return address;
}

ipv6_address address_factory::parse_address_as_ipv6(const std::string &str)
{
	std::stringstream str_stream(str);
	ipv6_address address = parse_ipv6_address(str, str_stream);
	char c = str_stream.peek();
	if(c != EOF)
	{
		std::string s("Unexpected character: ");
		s += c;
		throw std::invalid_argument(s);
	}
	return address;
}

ipv4_address address_factory::parse_subnet_address_as_ipv4(const std::string& str)
{
	std::stringstream str_stream(str);
	ipv4_address address = address_factory::parse_ipv4_address(str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");

	unsigned int temp;
	str_stream >> std::dec >> temp;
	address.subnet_bits = temp;
	return address;
}

ipv6_address address_factory::parse_subnet_address_as_ipv6(const std::string& str)
{
	std::stringstream str_stream(str);
	ipv6_address address = address_factory::parse_ipv6_address(str, str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");
	unsigned int temp;
	str_stream >> std::dec >> temp;
	address.subnet_bits = temp;
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

mac_address address_factory::parse_mac_address(const std::string &str)
{
	std::stringstream str_stream(str);
	mac_address address;
	for (int i = 0; i < 6; i++)
	{
		unsigned int temp; //I can't read into uint8_t because that gets interpreted as char
		str_stream >> std::hex >> temp;
		if (temp > std::numeric_limits<uint8_t>::max())
			throw std::invalid_argument("Value can't be more than ff.");
		address.data[i] = temp;

		if (i != 5 && str_stream.get() != '-')
			throw std::invalid_argument("Expected -");
	}
	return address;
}