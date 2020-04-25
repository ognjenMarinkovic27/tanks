#include <SFML/Graphics.hpp>

class Rigidbody {
    sf::Vector2f position;
    sf::Vector2f velocity;
    float rotation;
    public:
        Rigidbody();
        Rigidbody(float x, float y);
        void addVelocity(float x, float y);
        void setVelocity(float x, float y);
        void setPosition(float x, float y);
        void setRotation(float ang);
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        float getRotation();
};
