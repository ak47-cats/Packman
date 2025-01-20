#ifndef ASCI_CODES_HPP
#define ASCI_CODES_HPP

#include <string>

namespace Color {
    const std::string WHITE_B  = "\033[1;37m";
    const std::string YELLOW_B = "\033[1;33m";
    const std::string RED_B    = "\033[1;31m";

    const std::string CLEAR    = "\033[0m";
};

#endif // ASCI_CODES_HPP