#include<SFML/Graphics.hpp>

class GameMaster {
    int width, height;
    sf::RenderWindow gameWindow;
    public:
        GameMaster(int width, int height);
        bool run();
        void quit();
        void handleEvent();
};
