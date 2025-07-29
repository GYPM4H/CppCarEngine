#pragma once

#include "crankshaft.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class ConnectingRod {
    public:
    explicit ConnectingRod(sf::Vector2f rod_size);
    ~ConnectingRod();

    [[nodiscard]] sf::Vector2f get_rod_size() const;
    [[nodiscard]] sf::Vector2f get_current_top_rod_pos() const;
    [[nodiscard]] sf::Vector2f get_current_bottom_rod_pos() const;
    [[nodiscard]] sf::Vector2f get_current_midpoint_rod_pos() const;
    [[nodiscard]] float get_rod_angle() const;
    [[nodiscard]] float get_rod_length() const;

    void set_current_bottom_rod_pos(sf::Vector2f position);

    void update_pos(Crankshaft& c);

    friend std::ostream& operator<<(std::ostream& os, const ConnectingRod& r);

    private:
    sf::Vector2f rod_size;
    sf::Vector2f current_top_rod_pos;
    sf::Vector2f current_bottom_rod_pos;
    sf::Vector2f current_mid_point;
    float rod_angle;
    float length;
};