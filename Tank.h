#include <SFML/Graphics.hpp>
#include "Rigidbody.h"


class Tank {
    std::string name;
    sf::Color color;
    float pipeRotation = 45;

    Rigidbody* rb;
    public:
        Tank(std::string name, sf::Color color, Rigidbody* rb);
        sf::Color getColor();
        std::string getName();
        void travel(float speed);
        Rigidbody* getRigidbody();
        float getPipeRotation();
        void rotatePipe(float ang);

};
