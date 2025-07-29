#pragma once

#include <iostream>
#include <SFML/System/Vector2.hpp>

#include "utils.hpp"

class Crankshaft {
    public:
    int rpm;

    explicit Crankshaft(const int& rpm, const float& radius);
    ~Crankshaft() = default;

    void rotate(const float &delta);
    [[nodiscard]] float get_radius() const;
    [[nodiscard]] float get_angular_velocity() const;
    [[nodiscard]] float get_rad_angle() const;
    [[nodiscard]] sf::Vector2f get_center_position() const;
    [[nodiscard]] sf::Vector2f get_crank_pin_position() const;

    void set_crankshaft_center(sf::Vector2f center);

    friend std::ostream& operator<<(std::ostream& os, const Crankshaft& c);

    private:
    Stage current_stage;

    float angular_velocity;
    float current_angle;
    float radius;
    sf::Vector2f center_position;
    sf::Vector2f crank_pin_position;

    float compute_angular_velocity(const int& rpm);

};