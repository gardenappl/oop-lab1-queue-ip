#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"


struct ipv4_address : public ip_address
{
	std::uint8_t data[4];


	ipv4_address(uint8_t num1, uint8_t num2, uint8_t num3,
		uint8_t num4);

	ipv4_address() = default;

	bool operator<(const ipv4_address& address2) const;
	bool operator==(const ipv4_address& address2) const;
	void print(std::ostream& os) const;
	bool belongs_to_subnet(const ipv4_address& subnet_address) const;
};
