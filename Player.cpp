#include "Player.h"

Player::Player(std::string name, sf::Color color) {
    this->name = name;
    this->color = color;
}

sf::Color Player::getColor() {
    return color;
}

std::string Player::getName() {
    return name;
}
