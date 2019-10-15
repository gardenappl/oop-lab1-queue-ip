#pragma once

#include "ipv4_address.h"

#include <cstdint>
#include <iostream>


ipv4_address::ipv4_address(uint8_t num1, uint8_t num2, uint8_t num3,
		uint8_t num4)
{
	data[0] = num1;
	data[1] = num2;
	data[2] = num3;
	data[3] = num4;
}

void ipv4_address::print(std::ostream& os) const
{
	os << (int)data[0] << '.' << (int)data[1] << '.' << (int)data[2] << '.' << (int)data[3];
	if (subnet_bits != -1)
		os << '/' << (int)subnet_bits;
}

bool ipv4_address::belongs_to_subnet(const ipv4_address& subnet_address) const
{
	size_t i = 0;
	for (; (i + 1) * 8 <= 32 - subnet_address.subnet_bits; i++)
	{
		if (data[i] != subnet_address.data[i])
			return false;
	}
	//partially compare
	int remaining_bits = subnet_address.subnet_bits % 8;
	if (remaining_bits != 0)
	{
		if (data[i] >> remaining_bits != subnet_address.data[i] >> remaining_bits)
			return false;
	}
	return true;
}