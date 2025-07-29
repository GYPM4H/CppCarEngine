#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#endif //WINDOWMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class WindowManager {
public:
    WindowManager(unsigned int width, unsigned int height, const std::string& title, int antiAliasingLevel);

    sf::RenderWindow& get();
    sf::Vector2f get_center() const;
    sf::Vector2u get_size() const;

private:
    sf::RenderWindow window;
    sf::ContextSettings settings;
    sf::Vector2u size;
};