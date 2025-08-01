#include "crankshaft.hpp"
#include <cmath>
#include <iomanip>


Crankshaft::Crankshaft(const int &rpm, const float &radius) {
    this->current_angle = 0;
    this->current_stage = Stage::Intake;
    this->rpm = rpm;
    this->radius = radius;
    this->angular_velocity = compute_angular_velocity(this->rpm);
    this->center_position = {0,0};
    this->crank_pin_position = {this->center_position.x + this->radius * std::cos(this->current_angle),
                                    this->center_position.y + this->radius * std::sin(this->current_angle)};
}

float Crankshaft::compute_angular_velocity(const int &rpm) {
    const float angular_velocity = (2 * M_PI * rpm) / 60.0;
    return angular_velocity;
}

void Crankshaft::rotate(const float &delta) {
    float step_angle = this->current_angle + this->angular_velocity * delta;
    step_angle = fmod(step_angle, 4 * M_PI);
    this->current_angle = step_angle;

    auto [x, y] = this->center_position;
    float crank_pin_init_x_pos = x + this->radius * std::cos(this->current_angle);
    float crank_pin_init_y_pos = y + this->radius * std::sin(this->current_angle);
    this->crank_pin_position = {crank_pin_init_x_pos, crank_pin_init_y_pos};

    if (this->current_angle < M_PI) {
        this->current_stage = Stage::Intake;
    }
    else if (this->current_angle < 2 * M_PI) {
        this->current_stage = Stage::Compression;
    }
    else if (this->current_angle < 3 * M_PI) {
        this->current_stage = Stage::Combustion;
    }
    else if (this->current_angle <= 4 * M_PI) {
        this->current_stage = Stage::Exhaust;
    }
}

float Crankshaft::get_radius() const {
    return this->radius;
}

float Crankshaft::get_angular_velocity() const {
    return this->angular_velocity;
}

float Crankshaft::get_rad_angle() const {
    return this->current_angle;
}

sf::Vector2f Crankshaft::get_center_position() const {
    return this->center_position;
}

sf::Vector2f Crankshaft::get_crank_pin_position() const {
    return this->crank_pin_position;
}

void Crankshaft::set_crankshaft_center(sf::Vector2f center) {
    this->center_position = center;
}

std::ostream & operator<<(std::ostream &os, const Crankshaft &c) {
    const float angle_deg = (180.0 * c.current_angle) / M_PI;
    os << std::fixed << std::setprecision(2);
    os << "Crankshaft angles: "
       << angle_deg << " degrees / "
       << c.current_angle << " radians."
       << " Current stage is " << stage_to_string(c.current_stage) << '\n';
    return os;
}


