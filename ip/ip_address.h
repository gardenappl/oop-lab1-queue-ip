#pragma once

#include <iostream>

/*!
 * An abstract class for representing IP addresses.
 */
struct ip_address
{
    /*!
     * The subnetwork mask. Value of -1 indicates that this address is not a subnetwork.
     */
	std::int8_t subnet_bits = -1;

private:
    virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const ip_address& address);
};

std::ostream& operator<<(std::ostream& os, const ip_address& address);