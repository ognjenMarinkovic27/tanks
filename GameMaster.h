#include<SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "TerrainGenerator.h"
#include "Tank.h"

#ifndef GAMEMASTER_h
#define GAMEMASTER_h


class GameMaster {
    unsigned screenWidth, screenHeight;
    sf::RenderWindow gameWindow;

    TerrainGenerator tg;

    PhysicsEngine pe;

    int playerCount=5;
    std::vector<Tank> tanks;

    int currentPlayerIndex = 0;

    public:
        GameMaster(unsigned width, unsigned height);
        void run();
        void quit();
        void handleEvent();
        void drawTerrain();
};

#endif // GAMEMASTER_h
