#include "ip/ipv4_address.h"
#include "ipv4_address_subnet.h"

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

std::ostream& operator<<(std::ostream& os, const ipv4_address& address)
{
	os << (int16_t)address.data[0] << '.' << (int16_t)address.data[1] << '.'
			<< (int16_t)address.data[2] << '.' << (int16_t)address.data[3];
	return os;
}
bool ipv4_address::operator<(const ipv4_address &address2) const
{
    for(size_t i = 0; i < 4; i++)
    {
        if(data[i] < address2.data[i])
            return true;
        else if(data[i] > address2.data[i])
            return false;
    }
    return false;
}