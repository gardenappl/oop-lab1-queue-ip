#pragma once

#include "ipv6_address.h"

#include <cstdint>
#include <iostream>


ipv6_address::ipv6_address(uint16_t data[8])
{
	for (int i = 0; i < 8; i++)
		this->data[i] = data[i];
}

void ipv6_address::print(std::ostream& os) const
{
	os << std::hex << data[0];
	for (int i = 1; i < 8; i++)
		os << ':' << data[i];
	os << std::dec;
	if (subnet_bits != -1)
		os << '/' << (int)subnet_bits;
}

bool ipv6_address::belongs_to_subnet(const ipv6_address& subnet_address) const
{
	size_t i = 0;
	for (; (i + 1) * 32 <= 128 - subnet_address.subnet_bits; i++)
	{
		if (data[i] != subnet_address.data[i])
			return false;
	}
	//partially compare
	int remaining_bits = subnet_address.subnet_bits % 32;
	if (remaining_bits != 0)
	{
		if (data[i] >> remaining_bits != subnet_address.data[i] >> remaining_bits)
			return false;
	}
	return true;
}