#include "Weapon.h"
#include <math.h>

Weapon::Weapon() {
    name = "undefined";
}

Weapon::Weapon(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage)
{
    this->name = name;
    this->color = color;
    this->rb = rb;
    rb->setTravel(false);
    this->radius = radius;
    this->damage = damage;
}

sf::Color Weapon::getColor() {
    return color;
}

std::string Weapon::getName() {
    return name;
}

float Weapon::getRadius() {
    return radius;
}

Rigidbody* Weapon::getRigidbody() {
    return rb;
}

void Weapon::setProperties(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage) {
    this->name = name;
    this->color = color;
    this->rb = rb;
    rb->setTravel(false);
    this->radius = radius;
    this->damage = damage;
}

void Weapon::shoot(float x, float y)
{
    rb->setVelocity(x, y);
}

void Weapon::destroy()
{
    bool** terrain = tg.getTerrain();
    float x = rb->getPosition().x;
    float y = rb->getPosition().y;
    for(int i=0; i<radius; i++)
    {
        for(int j=0; j<radius; j++)
        {

            terrain[(int)x+i][(int)y+j]=0;
            terrain[(int)x-i][(int)y-j]=0;
            terrain[(int)x+i][(int)y-j]=0;
            terrain[(int)x-i][(int)y+j]=0;
        }
    }
}

