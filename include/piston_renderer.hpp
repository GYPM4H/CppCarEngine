#ifndef PISTON_RENDERER_HPP
#define PISTON_RENDERER_HPP

#endif //PISTON_RENDERER_HPP
#include <piston.hpp>
#include <SFML/Graphics.hpp>

class PistonRenderer {
public:
    explicit PistonRenderer(const Piston& p, sf::Color color);
    ~PistonRenderer() = default;

    void draw(sf::RenderWindow& window) const;
    void sync(const Piston& p);

private:
    sf::RectangleShape piston_obj;
    sf::Vector2f center_coords;

    const sf::Color pin_color = sf::Color::Red;
};

