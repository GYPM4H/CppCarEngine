#include "piston.hpp"

Piston::Piston(sf::Vector2f size) {
    this->position = {0, 0};
    this->size = size;
}

sf::Vector2f Piston::get_position() const {
    return this->position;
}

sf::Vector2f Piston::get_size() const {
    return this->size;
}

void Piston::set_position(sf::Vector2f pos) {
    this->position = pos;
}

std::ostream & operator<<(std::ostream &os, const Piston &p) {
    os << "Piston position is " << p.position.x << "|" << p.position.y << '.' << ' ';
    return os;
}
