#include "ip/ipv6_address.h"

#include <cstdint>
#include <iostream>
#include <limits>


ipv6_address::ipv6_address(uint8_t data[16])
{
	for (size_t i = 0; i < 16; i++)
		this->data[i] = data[i];
}

ipv6_address::ipv6_address(const ipv4_address& address)
{
	for (size_t i = 0; i < 10; i++)
		this->data[i] = 0;
	this->data[10] = 0xffu;
	this->data[11] = 0xffu;
	for(size_t i = 0; i < 4; i++)
		this->data[12 + i] = address.data[i];
}

std::ostream& operator<<(std::ostream& os, const ipv6_address& address)
{
	std::ios_base::fmtflags prev_flags = os.flags();

	//Find largest sequence of zeroes to shorten.
	//If sequence has length 1, ignore
	//If there are multiple largest sequences, pick leftmost one.
	int longest_zero_sequence = std::numeric_limits<int>::max();
	int longest_zero_sequence_length = 0;
	int current_zero_sequence_length = 0;
	for(int i = 0; i < 8; i++)
	{
		if(address.data[i * 2] == 0 && address.data[i * 2 + 1] == 0)
		{
			current_zero_sequence_length++;
		}
		else
		{
			if (current_zero_sequence_length > 1 && current_zero_sequence_length > longest_zero_sequence_length)
			{
				longest_zero_sequence_length = current_zero_sequence_length;
				longest_zero_sequence = i - current_zero_sequence_length;
			}
			current_zero_sequence_length = 0;
		}
	}
	if(current_zero_sequence_length > 1 && current_zero_sequence_length > longest_zero_sequence_length)
	{
		longest_zero_sequence_length = current_zero_sequence_length;
		longest_zero_sequence = 8 - current_zero_sequence_length;
	}

	bool printing_zero_sequence = false;
	for (int i = 0; i < 8; i++)
	{
		if(i == longest_zero_sequence)
		{
			os << "::";
			i = longest_zero_sequence + longest_zero_sequence_length - 1;
			printing_zero_sequence = true;
			continue;
		}
		if(i != 0 && !printing_zero_sequence)
			os << ':';
		printing_zero_sequence = false;
		if(address.data[2 * i] != 0)
			os << std::hex << (int16_t)address.data[2 * i];
		os << std::hex << (int16_t)address.data[2 * i + 1];
	}
	os.flags(prev_flags);
	return os;
}

bool ipv6_address::operator<(const ipv6_address &address2) const
{
	for(size_t i = 0; i < 8; i++)
	{
		if(data[i] < address2.data[i])
			return true;
		else if(data[i] > address2.data[i])
			return false;
	}
	return false;
}