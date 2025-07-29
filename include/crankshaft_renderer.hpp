#ifndef CRANKSHAFT_RENDERER_HPP
#define CRANKSHAFT_RENDERER_HPP

#endif //CRANKSHAFT_RENDERER_HPP

#include "crankshaft.hpp"
#include "SFML/Graphics.hpp"

class CrankshaftRenderer {
    public:
    explicit  CrankshaftRenderer(const Crankshaft& c, sf::Color color);
    ~CrankshaftRenderer() = default;

    void draw(sf::RenderWindow& window) const;
    void sync(const Crankshaft& c);

    private:
    sf::CircleShape crank_obj;
    sf::CircleShape crank_pin;
    sf::Vector2f center_coords;
    float radius;
    float shaft_angle;

    const float pin_radius = 10;
    const sf::Color pin_color = sf::Color::Blue;
};