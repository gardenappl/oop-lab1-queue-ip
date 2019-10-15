#pragma once

#include <cstdint>
#include <iostream>
#include "ip_address.h"


struct ipv6_address : public ip_address
{
	union
	{
		std::uint16_t data[8];
	};

	ipv6_address(uint16_t data[8]);

	ipv6_address() = default;

	void print(std::ostream& os) const;
	bool belongs_to_subnet(const ipv6_address& subnet_address) const;
};