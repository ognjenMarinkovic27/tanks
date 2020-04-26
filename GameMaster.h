#include<SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "TerrainGenerator.h"
#include "Player.h"

class GameMaster {
    unsigned screenWidth, screenHeight;
    sf::RenderWindow gameWindow;

    TerrainGenerator tg;

    PhysicsEngine pe;

    int playerCount=5;
    std::vector<Player> players;

    public:
        GameMaster(unsigned width, unsigned height);
        void run();
        void quit();
        void handleEvent();
        void drawTerrain();
};
