#include "connecting_rod.hpp"
#include <cmath>
#include <iomanip>


ConnectingRod::ConnectingRod(const sf::Vector2f rod_size) {
    this->rod_size = rod_size;
    this->current_bottom_rod_pos = {0,0};
    this->current_top_rod_pos = {0,0};
}

ConnectingRod::~ConnectingRod() = default;


sf::Vector2f ConnectingRod::get_rod_size() const {
    return this->rod_size;
}

sf::Vector2f ConnectingRod::get_current_top_rod_pos() const {
    return this->current_top_rod_pos;
}

sf::Vector2f ConnectingRod::get_current_bottom_rod_pos() const {
    return this->current_bottom_rod_pos;
}

sf::Vector2f ConnectingRod::get_current_midpoint_rod_pos() const {
    return this->current_mid_point;
}

float ConnectingRod::get_rod_angle() const {
    return  this->rod_angle;
}

float ConnectingRod::get_rod_length() const {
    return this->length;
}

void ConnectingRod::set_current_bottom_rod_pos(sf::Vector2f position) {
    this->current_bottom_rod_pos = position;
}

void ConnectingRod::update_pos(Crankshaft& c) {
    float shaft_radius = c.get_radius();
    float shaft_angle = c.get_rad_angle();
    float rod_length = this->rod_size.x;

    sf::Vector2f crank_center = c.get_center_position();
    sf::Vector2f crank_pin_pos = c.get_crank_pin_position();

    float dx = crank_pin_pos.x - crank_center.x;
    float dy = std::sqrt(rod_length * rod_length - dx * dx);

    float top_rod_y_pos = crank_center.y - dy;

    this->current_top_rod_pos = {crank_center.x, top_rod_y_pos};
    this->current_bottom_rod_pos = crank_pin_pos;
    this->current_mid_point = {
        (this->current_bottom_rod_pos.x + this->current_top_rod_pos.x) / 2.0f,
        (this->current_bottom_rod_pos.y + this->current_top_rod_pos.y) / 2.0f
    };

    this->rod_angle = std::atan2(dy, dx);
    this->length = std::sqrt(dx * dx + dy * dy);
}

std::ostream& operator<<(std::ostream &os, const ConnectingRod &r) {
    os << std::setprecision(2);
    os << std::fixed;
    os << "Rod top position is " << r.get_current_top_rod_pos().x << "|" << r.get_current_top_rod_pos().y << '.' << ' ';
    return os;
}
