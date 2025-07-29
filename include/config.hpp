#ifndef CONFIG_HPP
#define CONFIG_HPP

#endif //CONFIG_HPP
#include <string>

namespace Physics {
    constexpr int rpm = 100;
    constexpr float shaft_radius = 50;
    constexpr sf::Vector2f rod_size = {150, 10};
    constexpr float delta = 0.0001f;
    constexpr sf::Vector2f piston_size = {100, 50};
}

namespace Screen {
    constexpr int width = 800;
    constexpr int height = 600;
    constexpr int antiAliasingLevel = 8;
    std::string title = "Window";
}