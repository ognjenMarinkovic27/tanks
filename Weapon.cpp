#include "Weapon.h"
#include <math.h>

Weapon::Weapon(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage)
{
    this->name = name;
    this->color = color;
    this->rb = rb;
    radius = 10;
    damage = 10;
}

sf::Color Weapon::getColor() {
    return color;
}

std::string Weapon::getName() {
    return name;
}

Rigidbody* Weapon::getRigidbody() {
    return rb;
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

