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
        Weapon();
        Weapon(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage, TerrainGenerator tg);
        sf::Color getColor();
        std::string getName();
        float getRadius();
        Rigidbody* getRigidbody();
        void setProperties(std::string name, sf::Color color, Rigidbody* rb, float radius, float damage, TerrainGenerator tg);
        void shoot(float x, float y);
        void destroy();
};
