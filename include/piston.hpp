#ifndef PISTON_HPP
#define PISTON_HPP

#include <SFML/Graphics.hpp>

class Piston {
    public:
    explicit Piston(sf::Vector2f size);

    ~Piston() = default;

    [[nodiscard]] sf::Vector2f get_position() const;
    [[nodiscard]] sf::Vector2f get_size() const;

    void set_position(sf::Vector2f pos);

    friend std::ostream& operator<<(std::ostream& os, const Piston& p);

    private:
    sf::Vector2f position;
    sf::Vector2f size;
};

#endif