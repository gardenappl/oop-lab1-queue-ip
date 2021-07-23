#include "ip/address_factory.h"
#include "ip/ipv4_address.h"
#include "ip/ipv6_address.h"
#include "ipv4_address_subnet.h"
#include "ipv6_address_subnet.h"
#include <stdexcept>
#include <sstream>
#include <limits>
#include <random>

ipv4_address address_factory::random_ipv4_address()
{
	static std::default_random_engine rng;
	static std::uniform_int_distribution<uint8_t> dist(0, std::numeric_limits<uint8_t>::max());
	std::cout << "Generated thing" << std::endl;
	return ipv4_address(dist(rng), dist(rng), dist(rng), dist(rng));
}

ipv6_address address_factory::random_ipv6_address()
{
	static std::default_random_engine rng;
	static std::uniform_int_distribution<uint8_t> dist(0, std::numeric_limits<uint8_t>::max());
	uint8_t data[16];
	for(size_t i = 0; i < 16; i++)
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

		int parsed_num = 0;
		bool used_zero_substitution = false;

		for (; parsed_num < 8; parsed_num++)
		{
			if(str_stream.peek() == ':')
			{
				if(parsed_num == 0)
					str_stream.ignore();
				if (str_stream.get() != ':')
					throw std::invalid_argument("Expected ::");
				used_zero_substitution = true;
				break;
			}
			str_stream >> std::hex >> address.data[parsed_num];

			if (parsed_num != 7 && str_stream.get() != ':')
				throw std::invalid_argument("Expected :");
		}

		if(used_zero_substitution)
		{
			uint16_t end_bits[7];

			int j = 0;
			for(; j < 8 - parsed_num - 1; j++)
			{
				char c = str_stream.peek();
				if(!isdigit(c) && !(c >= 'a' && c <= 'f'))
					break;
				str_stream >> std::hex >> end_bits[j];

				if (str_stream.get() != ':')
				{
					j++;
					break;
				}
			}
			for(int i = parsed_num; i < 8 - j; i++)
			{
				address.data[i] = 0;
			}
			for(int i = 0; i < j; i++)
			{
				address.data[8 - j + i] = end_bits[i];
			}
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

ipv4_address_subnet address_factory::parse_subnet_address_as_ipv4(const std::string& str)
{
	std::stringstream str_stream(str);
	ipv4_address address = address_factory::parse_ipv4_address(str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");

	int subnet_bits;
	str_stream >> std::dec >> subnet_bits;
	return ipv4_address_subnet(address, (uint8_t)subnet_bits);
}

ipv6_address_subnet address_factory::parse_subnet_address_as_ipv6(const std::string& str)
{
	std::stringstream str_stream(str);
	ipv6_address address = address_factory::parse_ipv6_address(str, str_stream);
	if (str_stream.get() != '/')
		throw std::invalid_argument("Expected /");
	unsigned int subnet_bits;
	str_stream >> std::dec >> subnet_bits;
	return ipv6_address_subnet(address, subnet_bits);
}

ipv6_address address_factory::local_ipv6_from_mac_auto(const mac_address &mac)
{
	uint8_t address_data[16];
	//prefix for auto-configured addresses
	address_data[0] = 0xFEu;
	address_data[1] = 0x80u;
	for(int i = 2; i < 8; i++)
		address_data[i] = 0;
	//EUI-64
	for(int i = 0; i < 3; i++)
		address_data[8 + i] = mac.data[i];
	address_data[11] = 0xFFu;
	address_data[12] = 0xFEu;
	for(int i = 0; i < 3; i++)
		address_data[13 + i] = mac.data[3 + i];

	//flip the "universal/local" bit of the EUI-64
	address_data[8] ^= 1u << 1;
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