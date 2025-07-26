#include <iostream>
#include <crankshaft.hpp>
#include <connecting_rod.hpp>

int main() {
    constexpr int rpm = 2000;
    constexpr float delta = 0.001;
    constexpr int run_time = 100;
    constexpr float shaft_radius = 10;
    constexpr float rod_length = 15;

    Crankshaft crankshaft(rpm, shaft_radius);
    ConnectingRod connecting_rod(rod_length);

    std::cout << "Crankshaft radius is: " << crankshaft.get_radius() << '\n';
    std::cout << "Crankshaft angular velocity is: " << crankshaft.get_angular_velocity() << '\n';
    std::cout << "Connecting Rod length is: " << connecting_rod.get_rod_length() << '\n';
    float piston_position;
    for (int i = 0; i < run_time; i++) {
        crankshaft.rotate(delta);
        connecting_rod.update_top_rod_pos(crankshaft);

        std::cout << connecting_rod;
        std::cout << crankshaft;
    }


    return 0;
}