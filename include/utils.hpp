#ifndef UTILS_HPP
#define UTILS_HPP

#endif //UTILS_HPP

#include <string>

enum class Stage {
    Intake = 1,
    Compression = 2,
    Combustion = 3,
    Exhaust = 4,
};

std::string stage_to_string(Stage s);