#ifndef CRANKSHAFT_H
#define CRANKSHAFT_H

#endif //CRANKSHAFT_H


class Crankshaft {
    public:
    int rpm;
    float angular_velocity;

    Crankshaft(int rpm, int angle);
    ~Crankshaft();

    float compute_angular_velocity(int rpm, int);

};