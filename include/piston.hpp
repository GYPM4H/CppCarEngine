#ifndef PISTON_HPP
#define PISTON_HPP
#include <iosfwd>

#endif //PISTON_HPP

#include <iostream>

class Piston {
public:
    float position;

    explicit Piston(): position(0) {
    }

    ~Piston() = default;

    void set_position(float pos);

    friend std::ostream& operator<<(std::ostream& os, const Piston& p);


};