#pragma once

#include <iostream>

struct ip_address
{
	std::int8_t subnet_bits = -1;

	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const ip_address& address);
};

std::ostream& operator<<(std::ostream& os, const ip_address& address);