#include <iostream>

#include <memory>
#include "interactive/interactive_mode.h"

int main(int argc, char **argv) {
    auto interactive = std::make_unique<interactive_mode>();
    interactive->run(std::cout, std::cin);

    return 0;
}
