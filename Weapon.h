#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "TerrainGenerator.h"

class Weapon
{
    float radius;
    float damage;
    sf::Color color;
    std::string name;
    Rigidbody* rb;
    TerrainGenerator tg;

    public:
        Weapon(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage);
        sf::Color getColor();
        std::string getName();
        Rigidbody* getRigidbody();
        void shoot(float x, float y);
        void destroy();
};
