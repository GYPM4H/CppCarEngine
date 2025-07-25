#include <iostream>
#include <crankshaft.hpp>

int main() {
    constexpr int rpm = 2000;
    constexpr float delta = 0.0001;
    constexpr int run_time = 1000;

    Crankshaft crankshaft(rpm);



    for (int i = 0; i < run_time; i++) {
        crankshaft.rotate(delta);
        std::cout << crankshaft;
    }


    return 0;
}