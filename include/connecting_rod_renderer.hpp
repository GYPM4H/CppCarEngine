#ifndef CONNECTING_ROD_RENDERER_HPP
#define CONNECTING_ROD_RENDERER_HPP
#endif //CONNECTING_ROD_RENDERER_HPP

#include "SFML/Graphics.hpp"
#include "connecting_rod.hpp"
#include "crankshaft.hpp"


class ConnectingRodRenderer {
    public:
    explicit  ConnectingRodRenderer(const ConnectingRod& c, sf::Color color);
    ~ConnectingRodRenderer() = default;

    void draw(sf::RenderWindow& window) const;
    void sync(const ConnectingRod& c);

private:
    sf::RectangleShape rod_obj;
    sf::Vector2f position;
    sf::Vector2f size;
};