#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() {
    position.first = 0.0;
    position.second = 0;
    velocity.first = 0;
    velocity.second = 0;
}

Rigidbody::Rigidbody(float x, float y) {
    position.first = x;
    position.second = y;
    velocity.first = 0;
    velocity.second = 0;
}

void Rigidbody::addVelocity(float x, float y) {
    velocity.first+=x;
    velocity.second+=y;
}

void Rigidbody::setVelocity(float x, float y) {
    velocity.first=x;
    velocity.second=y;
}

std::pair<float, float> Rigidbody::getPosition() {
    return position;
}

void Rigidbody::setPosition(float x, float y) {
    position.first = x;
    position.second = y;
}

std::pair<float, float> Rigidbody::getVelocity() {
    return velocity;
}
