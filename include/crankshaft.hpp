#ifndef CRANKSHAFT_H
#define CRANKSHAFT_H

#endif

#include <iostream>
#include "utils.hpp"

class Crankshaft {
    public:
    int rpm;

    explicit Crankshaft(const int& rpm);
    ~Crankshaft();

    void rotate(const float &delta);

    friend std::ostream& operator<<(std::ostream& os, const Crankshaft& c);

    private:
    Stage current_stage;

    float angular_velocity;
    float current_angle;


    float compute_angular_velocity(const int& rpm);

};