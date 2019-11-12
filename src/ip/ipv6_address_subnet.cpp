#include "ip/ipv6_address_subnet.h"

ipv6_address_subnet::ipv6_address_subnet(uint8_t data[16], uint8_t subnet_bits)
		: address(data), subnet_bits(subnet_bits)
{}

ipv6_address_subnet::ipv6_address_subnet(const ipv6_address& address, uint8_t subnet_bits)
		: address(address), subnet_bits(subnet_bits)
{}

std::ostream& operator<<(std::ostream& os, const ipv6_address_subnet& address)
{
	os << address.address;
	os << std::dec << '/' << (int16_t)address.subnet_bits;
	return os;
}

bool ipv6_address_subnet::belongs_to_subnet(const ipv6_address& address2) const
{
	size_t i = 0;
	for (; (i + 1) * 8 <= 128 - subnet_bits; i++)
	{
		//std::cout << "compare " << std::hex << data[i] << " and " << std::hex << subnet_address.address.data[i] << std::endl;
		if (address.data[i] != address2.data[i])
			return false;
	}
	//partially compare
	int remaining_bits = subnet_bits % 8;
	if (remaining_bits != 0)
	{
		if (address.data[i] >> remaining_bits != address2.data[i] >> remaining_bits)
			return false;
	}
	return true;
}