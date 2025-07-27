#include <iostream>
#include <crankshaft.hpp>
#include <connecting_rod.hpp>
#include <piston.hpp>
#include <SFML/Graphics.hpp>

int main() {
    constexpr int rpm = 2000;
    constexpr int run_time = 100;
    constexpr float shaft_radius = 10;
    constexpr float rod_length = 15;
    constexpr float delta = 0.001;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "MyWindow");
    sf::Vector2u window_size = window.getSize();

    float width = window_size.x;
    float height = window_size.y;

    std::cout << width << '\n' << height << '\n';

    Crankshaft crankshaft(rpm, shaft_radius);
    ConnectingRod connecting_rod(rod_length);
    Piston piston;

    sf::CircleShape crankshaft_obj(50.f);
    crankshaft_obj.setPosition(sf::Vector2f((width / 2) - 50, (height / 2) - 50));
    crankshaft_obj.setPointCount(50);
    crankshaft_obj.setFillColor(sf::Color::Green);


    sf::RectangleShape connecting_rod_obj({50.f, 5.f});
    connecting_rod_obj.setPosition(sf::Vector2f(width / 2, height / 2));


    sf::RectangleShape piston_obj({75.f, 75.f});

    std::cout << "Crankshaft radius is: " << crankshaft.get_radius() << '\n';
    std::cout << "Crankshaft angular velocity is: " << crankshaft.get_angular_velocity() << '\n';
    std::cout << "Connecting Rod length is: " << connecting_rod.get_rod_length() << '\n';
    float piston_position;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        for (int i = 0; i < run_time; i++) {
            crankshaft.rotate(delta);
            connecting_rod.update_top_rod_pos(crankshaft);
            piston.set_position(connecting_rod.get_top_rod_pos());

            std::cout << connecting_rod;
            std::cout << crankshaft;
            std::cout << piston;
        }

        window.clear(sf::Color::Black);
        window.draw(crankshaft_obj);
        window.draw(connecting_rod_obj);
        window.draw(piston_obj);
        window.display();
    }


    return 0;
}