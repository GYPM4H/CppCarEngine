#include "piston.hpp"


void Piston::set_position(float pos) {
    this->position = pos;
}

std::ostream & operator<<(std::ostream &os, const Piston &p) {
    os << "Piston position: " << p.position << '\n';
    return os;
}
