#include "utils.hpp"

std::string stage_to_string(Stage s) {
    switch (s) {
        case Stage::Intake:      return "Intake";
        case Stage::Compression: return "Compression";
        case Stage::Combustion:  return "Combustion";
        case Stage::Exhaust:     return "Exhaust";
        default:                 return "Unknown";
    }
}

