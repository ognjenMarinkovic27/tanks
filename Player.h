#include <SFML/Graphics.hpp>

class Player {
    std::string name;
    sf::Color color;
    public:
        Player(std::string name, sf::Color color);
        sf::Color getColor();
        std::string getName();
};
