#include<SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "TerrainGenerator.h"
#include "Tank.h"
#include "Weapon.h"

#ifndef GAMEMASTER_h
#define GAMEMASTER_h


class GameMaster {
    unsigned screenWidth, screenHeight;
    sf::RenderWindow gameWindow;

    TerrainGenerator tg;

    PhysicsEngine pe;

    Weapon currentWeapon;
    sf::CircleShape currentWeaponSprite;

    std::string* names;

    int playerCount=5;
    std::vector<Tank> tanks;

    int currentPlayerIndex = 0;

    bool isShooting = false;

    public:
        GameMaster(unsigned width, unsigned height, int playerCount, std::string* names);
        void run();
        void quit();
        void handleEvent();
        void drawTerrain();
};

#endif // GAMEMASTER_h
