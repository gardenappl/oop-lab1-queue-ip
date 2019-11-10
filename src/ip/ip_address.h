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
	/*!
	 * Prints a text representation of the IP address into the output stream.
	 * This method is invoked by the << operator.
	 * \param os the text output stream
	 */
	virtual void print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const ip_address& address);
};


/*!
 * Prints a text representation of the IP address into the output stream.
 * \param os the text output stream
 * \param address the IP address
 * \return the output stream after the IP address has been printed
 */
std::ostream& operator<<(std::ostream& os, const ip_address& address);