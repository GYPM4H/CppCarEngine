#include <window_manager.hpp>
#include <SFML/Graphics.hpp>

WindowManager::WindowManager(unsigned int width, unsigned int height, const std::string &title, int antiAliasingLevel) {
    this->settings.antiAliasingLevel = antiAliasingLevel;
    this->size = {width, height};

    this->window.create(
        sf::VideoMode(this->size),
        title,
        sf::Style::Default,
        sf::State::Windowed,
        this->settings
        );
}

sf::RenderWindow & WindowManager::get() {
    return this->window;
}

sf::Vector2f WindowManager::get_center() const {
    sf::Vector2u window_size = this->window.getSize();
    return sf::Vector2f(window_size.x / 2, window_size.y / 2);
}

sf::Vector2u WindowManager::get_size() const {
    return this->window.getSize();
}

