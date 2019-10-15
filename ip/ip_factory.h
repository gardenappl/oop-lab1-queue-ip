#pragma once

#include "ip_address.h"
#include <string>
#include <sstream>

class ip_factory
{
private:
	static ip_address* parse_address(const std::string& str, std::stringstream& str_stream);

public:
	static ip_address* parse_address(const std::string& str);
	static ip_address* parse_subnetwork_address(const std::string& str);
};
