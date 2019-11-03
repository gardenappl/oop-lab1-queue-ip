#include "ipv6_address.h"

#include <cstdint>
#include <iostream>
#include <limits>


ipv6_address::ipv6_address(uint16_t data[8])
{
	for (size_t i = 0; i < 8; i++)
		this->data[i] = data[i];
}

ipv6_address::ipv6_address(const ipv4_address& address)
{
    for (size_t i = 0; i < 5; i++)
        this->data[i] = 0;
    this->data[5] = 0xffff;
    for(size_t i = 0; i < 2; i++)
        this->data[6 + i] = ((uint16_t)address.data[i * 2] << 8u) + address.data[i * 2 + 1];
}

void ipv6_address::print(std::ostream& os) const
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
        if(data[i] == 0)
        {
            current_zero_sequence_length++;
        }
        else if(current_zero_sequence_length > 1)
        {
            if(current_zero_sequence_length > longest_zero_sequence_length)
                longest_zero_sequence_length = current_zero_sequence_length;
            longest_zero_sequence = i - current_zero_sequence_length;
            current_zero_sequence_length = 0;
        }
    }
	for (int i = 0; i < 8; i++)
	{
	    if(i == longest_zero_sequence)
	    {
            os << ':';
            i = longest_zero_sequence + longest_zero_sequence_length - 1;
            continue;
        }
	    if(i != 0)
	        os << ':';
        os << std::hex << data[i];
    }
	os << std::dec;
	if (subnet_bits != -1)
		os << '/' << (int)subnet_bits;

	os.flags(prev_flags);
}

bool ipv6_address::belongs_to_subnet(const ipv6_address& subnet_address) const
{
	size_t i = 0;
	for (; (i + 1) * 16 <= 128 - subnet_address.subnet_bits; i++)
	{
	    std::cout << "compare " << std::hex << data[i] << " and " << std::hex << subnet_address.data[i] << std::endl;
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