#include <iostream>
#include <crankshaft.hpp>
#include <connecting_rod.hpp>
#include <piston.hpp>
#include <crankshaft_renderer.hpp>
#include <SFML/Graphics.hpp>
#include <config.hpp>
#include <window_manager.hpp>

#include "connecting_rod_renderer.hpp"
#include "piston_renderer.hpp"

int main() {
    WindowManager window_manager(Screen::width, Screen::height, Screen::title, Screen::antiAliasingLevel);
    auto& window = window_manager.get();
    const sf::Vector2f window_center = window_manager.get_center();

    Crankshaft crankshaft(Physics::rpm, Physics::shaft_radius);
    crankshaft.set_crankshaft_center(window_center);
    CrankshaftRenderer crankshaft_renderer(crankshaft, sf::Color::White);

    ConnectingRod connecting_rod(Physics::rod_size);
    connecting_rod.set_current_bottom_rod_pos(crankshaft.get_crank_pin_position());
    ConnectingRodRenderer connecting_rod_renderer(connecting_rod, sf::Color::Green);

    Piston piston(Physics::piston_size);
    constexpr float piston_offset = -150.0f;
    piston.set_position({crankshaft.get_center_position().x, crankshaft.get_center_position().y + piston_offset});
    PistonRenderer piston_renderer(piston, sf::Color::Red);


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        crankshaft.rotate(Physics::delta);
        connecting_rod.update_pos(crankshaft);
        piston.set_position(connecting_rod.get_current_top_rod_pos());

        crankshaft_renderer.sync(crankshaft);
        connecting_rod_renderer.sync(connecting_rod);
        piston_renderer.sync(piston);

        crankshaft_renderer.draw(window);
        connecting_rod_renderer.draw(window);
        piston_renderer.draw(window);

        // std::cout << connecting_rod;
        // std::cout << crankshaft;
        // std::cout << piston;

        window.display();
    }


    return 0;
}
