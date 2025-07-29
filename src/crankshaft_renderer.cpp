#include "crankshaft_renderer.hpp"
#include <cmath>

CrankshaftRenderer::CrankshaftRenderer(const Crankshaft& c, sf::Color color) {
    this->center_coords = c.get_center_position();
    this->radius = c.get_radius();
    this->shaft_angle = c.get_rad_angle();

    this->crank_obj.setRadius(this->radius);
    this->crank_obj.setOrigin({this->radius, this->radius});
    this->crank_obj.setPosition(this->center_coords);
    this->crank_obj.setFillColor(color);

    this->crank_pin.setRadius(this->pin_radius);
    this->crank_pin.setOrigin({this->pin_radius, this->pin_radius});

    this->crank_pin.setPosition(c.get_crank_pin_position());
    this->crank_pin.setFillColor(this->pin_color);
}

void CrankshaftRenderer::draw(sf::RenderWindow& window) const {
    window.draw(this->crank_obj);
    window.draw(this->crank_pin);
}

void CrankshaftRenderer::sync(const Crankshaft &c) {
    this->shaft_angle = c.get_rad_angle();
    this->crank_pin.setPosition(c.get_crank_pin_position());
}


