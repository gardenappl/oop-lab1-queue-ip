#include "ip/ipv4_address_subnet.h"

ipv4_address_subnet::ipv4_address_subnet(uint8_t num1, uint8_t num2, uint8_t num3,
		uint8_t num4, uint8_t subnet_bits)
		: address(num1, num2, num3, num4), subnet_bits(subnet_bits)
{}

ipv4_address_subnet::ipv4_address_subnet(ipv4_address address, uint8_t subnet_bits)
		: address(address), subnet_bits(subnet_bits)
{}

std::ostream& operator<<(std::ostream& os, const ipv4_address_subnet& address)
{
	os << address.address;
	os << std::dec << '/' << (int16_t)address.subnet_bits;
	return os;
}

bool ipv4_address_subnet::belongs_to_subnet(const ipv4_address& address2) const
{
	size_t i = 0;
	for (; (i + 1) * 8 <= 32 - subnet_bits; i++)
	{
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
