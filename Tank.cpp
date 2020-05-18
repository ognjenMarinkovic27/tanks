#include "Tank.h"
#include <math.h>

Tank::Tank(std::string name, sf::Color color, Rigidbody* rb) {
    this->name = name;
    this->color = color;
    this->rb = rb;
}

sf::Color Tank::getColor() {
    return color;
}

std::string Tank::getName() {
    return name;
}

void Tank::travel(float speed) {
     rb->setVelocity(speed*cos((rb->getRotation()+90)*3.1415927/180), -speed*sin((rb->getRotation()+90)*3.1415927/180));
}

Rigidbody* Tank::getRigidbody() {
    return rb;
}

float Tank::getPipeRotation() {
    return pipeRotation;
}

void Tank::rotatePipe(float ang) {
    pipeRotation+=ang;
}
