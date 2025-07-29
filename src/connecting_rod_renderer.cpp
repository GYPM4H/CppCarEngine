#include "connecting_rod_renderer.hpp"

ConnectingRodRenderer::ConnectingRodRenderer(const ConnectingRod& c, sf::Color color) {
    this->position = c.get_current_bottom_rod_pos();
    this->size = c.get_rod_size();
    this->rod_obj.setSize(this->size);
    this->rod_obj.setOrigin({this->size.x, this->size.y / 2});
    this->rod_obj.setPosition(c.get_current_bottom_rod_pos());
    this->rod_obj.setFillColor(color);
    this->rod_obj.rotate(sf::degrees(90));
}

void ConnectingRodRenderer::draw(sf::RenderWindow &window) const {
    window.draw(this->rod_obj);
}

void ConnectingRodRenderer::sync(const ConnectingRod &c) {
    const float length = c.get_rod_length();
    this->rod_obj.setSize({length, this->size.y });
    this->rod_obj.setOrigin({length / 2.0f, this->size.y / 2.0f});
    this->rod_obj.setPosition(c.get_current_midpoint_rod_pos());
    this->rod_obj.setRotation(sf::radians(c.get_rod_angle()));
}
