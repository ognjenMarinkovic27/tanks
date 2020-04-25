#include<SFML/Graphics.hpp>
#include "TerrainGenerator.h"
#include "PhysicsEngine.h"

class GameMaster {
    unsigned screenWidth, screenHeight;
    sf::RenderWindow gameWindow;

    TerrainGenerator tg;
    bool doUpdateTerrain = true;

    PhysicsEngine pe;

    public:
        GameMaster(unsigned width, unsigned height);
        void run();
        void quit();
        void handleEvent();
        void updateTerrain();
};
