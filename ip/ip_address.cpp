#pragma once

#include "ip_address.h"



std::ostream& operator<<(std::ostream& os, const ip_address& address)
{
	address.print(os);
	return os;
}