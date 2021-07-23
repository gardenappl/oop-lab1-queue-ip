#pragma once

#include <iostream>

/*!
 * An abstract class for representing IP addresses.
 * \tparam N number of bytes to store
 */
template<int N>
struct ip_address
{
	/*!
	 * The bytes of the address.
	 */
	std::uint8_t data[N];
};