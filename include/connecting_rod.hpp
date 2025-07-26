#pragma once

#include "crankshaft.hpp"
#include <iostream>

class ConnectingRod {
    public:
    explicit ConnectingRod(const float& rod_length);
    ~ConnectingRod();

    [[nodiscard]] float get_rod_length() const;
    [[nodiscard]] float get_top_rod_pos() const;

    void update_top_rod_pos(Crankshaft& c);

    friend std::ostream& operator<<(std::ostream& os, const ConnectingRod& r);

    private:
    float rod_length;
    float current_top_rod_pos;

};