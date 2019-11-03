#include <iomanip>
#include "mac_address.h"

#include "iostream"

mac_address::mac_address(uint8_t data[6])
{
    for(size_t i = 0; i < 6; i++)
        this->data[i] = data[i];
}

std::ostream& operator<<(std::ostream& os, const mac_address& address)
{
    std::ios_base::fmtflags prev_flags = os.flags();

    os << std::hex << std::setfill('0') << std::setw(2) << (int)address.data[0];
    for (int i = 1; i < 6; i++)
        os << '-' << std::setfill('0') << std::setw(2) << (int)address.data[i];

    os.flags(prev_flags);
    return os;
}

