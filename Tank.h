#include <SFML/Graphics.hpp>
#include "Rigidbody.h"


class Tank {
    std::string name;
    sf::Color color;
    float health = 100;
    float pipeRotation = 90;

    Rigidbody* rb;
    public:
        Tank(std::string name, sf::Color color, Rigidbody* rb);
        sf::Color getColor();
        std::string getName();
        void travel(float speed);
        Rigidbody* getRigidbody();
        void draw ();


};
