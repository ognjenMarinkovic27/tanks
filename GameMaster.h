#include<SFML/Graphics.hpp>
#include "TerrainGenerator.h"

class GameMaster {
    unsigned screenWidth, screenHeight;
    sf::RenderWindow gameWindow;

    TerrainGenerator tg;
    bool updateTerrain = true;

    public:
        GameMaster(unsigned width, unsigned height);
        bool run();
        void quit();
        void handleEvent();
};
