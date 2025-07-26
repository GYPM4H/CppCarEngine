#pragma once

#include <iostream>
#include "utils.hpp"

class Crankshaft {
    public:
    int rpm;

    explicit Crankshaft(const int& rpm, const float& radius);
    ~Crankshaft();

    void rotate(const float &delta);
    [[nodiscard]] float get_radius() const;
    [[nodiscard]] float get_angular_velocity() const;
    [[nodiscard]] float get_rad_angle() const;

    friend std::ostream& operator<<(std::ostream& os, const Crankshaft& c);

    private:
    Stage current_stage;

    float angular_velocity;
    float current_angle;
    float radius;


    float compute_angular_velocity(const int& rpm);

};