#include "piston_renderer.hpp"

PistonRenderer::PistonRenderer(const Piston &p, sf::Color color) {
    this->center_coords = p.get_position();
    this->piston_obj.setSize(p.get_size());
    this->piston_obj.setOrigin({this->piston_obj.getSize().x / 2, this->piston_obj.getSize().y});
    this->piston_obj.setPosition(p.get_position());
    this->piston_obj.setFillColor(color);
}

void PistonRenderer::draw(sf::RenderWindow &window) const {
    window.draw(piston_obj);
}

void PistonRenderer::sync(const Piston &p) {
    this->center_coords = p.get_position();
    this->piston_obj.setPosition(p.get_position());
}
