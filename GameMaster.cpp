#include "GameMaster.h"
#include "PhysicsObject.h"
#include <iostream>
#include <math.h>
#include <Windows.h>

GameMaster::GameMaster(unsigned width, unsigned height) {
    std::ios_base::sync_with_stdio(false);
    srand(time(NULL));
    screenWidth = width;
    screenHeight = height;
    tg.generateTerrain(width, height, rand()%(1000000-100000)+100000);
}

bool GameMaster::run() {
    gameWindow.create(sf::VideoMode(screenWidth, screenHeight), "Tanks", sf::Style::Close);
    PhysicsObject object(100, 500);

    while(gameWindow.isOpen()) {
        sf::Event evnt;
        while(gameWindow.pollEvent(evnt)) {
            switch(evnt.type) {
            case sf::Event::Closed:
                gameWindow.close();
                break;
            }
        }

        gameWindow.clear();

        updateTerrain();
        bool** terrain = tg.getTerrain();


        sf::CircleShape objectSprite(15.f);
        objectSprite.setFillColor(sf::Color::Red);
        objectSprite.setPosition(sf::Vector2f(object.getX()-15, screenHeight-(1+(object.getY()))-15));

        object.addVelocity(0, -0.2);
        if(terrain[(int)round(object.getX())][(int)round(object.getY())-15] == 1) {object.setVelocity(0.0, 0.0);}

        object.move();

        gameWindow.draw(objectSprite);
        gameWindow.display();


    }
}

void GameMaster::updateTerrain() {
    bool** terrain = tg.getTerrain();
    int tileSize = tg.getTileSize();

    int width = screenWidth/tileSize;
    int height = screenHeight/tileSize;
    int rectSize = tileSize;
    for(int i=0;i<width;i++) {
        int length=1;
        int startj=0;
        for(int j=0;j<height;j++) {
            if(j!=height-1 && terrain[i][j]==terrain[i][j+1]) {
                length++;
            }
            else {
                sf::RectangleShape tile(sf::Vector2f(tileSize, length));
                if(terrain[i][j] == 1)
                    tile.setFillColor(sf::Color::Green);
                else
                    tile.setFillColor(sf::Color::Blue);
                tile.setPosition(sf::Vector2f(i*tileSize,screenHeight-(startj+1+length)*tileSize));
                gameWindow.draw(tile);
                startj=j;
                length=1;
            }
        }
    }
    doUpdateTerrain=false;
}
