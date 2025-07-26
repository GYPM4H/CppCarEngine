#include "connecting_rod.hpp"
#include <cmath>
#include <iomanip>


ConnectingRod::ConnectingRod(const float& rod_length) {
    this->rod_length = rod_length;
}

ConnectingRod::~ConnectingRod() = default;


float ConnectingRod::get_rod_length() const {
    return this->rod_length;
}

float ConnectingRod::get_top_rod_pos() const {
    return this->current_top_rod_pos;
}

void ConnectingRod::update_top_rod_pos(Crankshaft& c) {
    float shaft_radius = c.get_radius();
    float shaft_angle = c.get_rad_angle();

    float top_rod_pos = shaft_radius * cos(shaft_angle)
              + sqrt(std::pow(this->rod_length, 2)
                           - std::pow(shaft_radius, 2)
                           * std::pow(sin(shaft_angle), 2));

    this->current_top_rod_pos = top_rod_pos;
}

std::ostream& operator<<(std::ostream &os, const ConnectingRod &r) {
    os << std::setprecision(2);
    os << std::fixed;
    os << "Rod top position is " << r.get_top_rod_pos() << '.' << ' ';
    return os;
}
