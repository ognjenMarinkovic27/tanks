#include "PhysicsObject.h"
#include <iostream>

PhysicsObject::PhysicsObject() {
    position.first = 0.0;
    position.second = 0;
    velocity.first = 0;
    velocity.second = 0;
}

PhysicsObject::PhysicsObject(float x, float y) {
    position.first = x;
    position.second = y;
    velocity.first = 0;
    velocity.second = 0;
}

void PhysicsObject::addVelocity(float x, float y) {
    velocity.first+=x;
    velocity.second+=y;
}

void PhysicsObject::setVelocity(float x, float y) {
    velocity.first=x;
    velocity.second=y;
}

float PhysicsObject::getX() {
    return position.first;
}

float PhysicsObject::getY() {
    return position.second;
}

void PhysicsObject::move() {
    std::cout << velocity.second << std::endl;
    position.first += velocity.first;
    position.second += velocity.second;
}
