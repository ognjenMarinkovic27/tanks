#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() {
    position.x = 0.0;
    position.y = 0;
    velocity.x = 0;
    velocity.y = 0;
}

Rigidbody::Rigidbody(float x, float y) {
    position.x = x;
    position.y = y;
    velocity.x = 0;
    velocity.y = 0;
}

void Rigidbody::addVelocity(float x, float y) {
    velocity.x+=x;
    velocity.y+=y;
}

void Rigidbody::setVelocity(float x, float y) {
    velocity.x=x;
    velocity.y=y;
}

sf::Vector2f Rigidbody::getPosition() {
    return position;
}

void Rigidbody::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

sf::Vector2f Rigidbody::getVelocity() {
    return velocity;
}

void Rigidbody::setRotation(float ang) {
    rotation=ang;
}

void Rigidbody::setTravel(bool t) {
    canTravel = t;
}

float Rigidbody::getRotation(){
    return rotation;
}

bool Rigidbody::getTravel() {
    return canTravel;
}

void Rigidbody::disableGravity() {
    useGravity = 0;
}

void Rigidbody::enableGravity() {
    useGravity = 1;
}

bool Rigidbody::getGravity() {
    return useGravity;
}
