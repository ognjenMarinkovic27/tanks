#include <SFML/Graphics.hpp>
#ifndef RIGIDBODY_h
#define RIGIDBODY_h

class Rigidbody {
    sf::Vector2f position;
    sf::Vector2f velocity;
    bool useGravity = true;
    bool canTravel = true;
    float rotation;
    public:
        Rigidbody();
        Rigidbody(float x, float y);
        void addVelocity(float x, float y);
        void setVelocity(float x, float y);
        void setPosition(float x, float y);
        void setRotation(float ang);
        void setTravel(bool t);
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        float getRotation();
        bool getTravel();
        void disableGravity();
        void enableGravity();
        bool getGravity();
};
#endif // RIGIDBODY_h
