#include "GameMaster.h"
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

void GameMaster::run() {
    gameWindow.create(sf::VideoMode(screenWidth, screenHeight), "Tanks", sf::Style::Close | sf::Style::Resize);

    Rigidbody object(100, 500);
    pe.addRigidbody(&object);

    while(gameWindow.isOpen()) {
        sf::Event evnt;
        while(gameWindow.pollEvent(evnt)) {
            switch(evnt.type) {
            case sf::Event::Closed:
                gameWindow.close();
                break;
            case sf::Event::Resized:
                break;
            }
        }

        gameWindow.clear();

        updateTerrain();
        bool** terrain = tg.getTerrain();
        std::vector<int> heightMap = tg.getHeightMap();





        sf::RectangleShape objectSprite(sf::Vector2f(30, 15));
        objectSprite.setOrigin(15.0f, 7.5f);
        objectSprite.setFillColor(sf::Color::Red);
        objectSprite.setPosition(sf::Vector2f(object.getPosition().x, screenHeight-(1+(object.getPosition().y))));
        objectSprite.setRotation(object.getRotation()-90);

        /*sf::RectangleShape line(sf::Vector2f(1280,4));
        line.setPosition(sf::Vector2f(object.getPosition().x, screenHeight-(1+(object.getPosition().y))));
        line.setRotation(object.getRotation()+90);
        line.setFillColor(sf::Color::Magenta);*/

        object.setVelocity(2*cos((object.getRotation()+90)*3.1415927/180), -2*sin((object.getRotation()+90)*3.1415927/180));


        pe.simulate(terrain, tg.getHeightMap());
        gameWindow.draw(objectSprite);
        //gameWindow.draw(line);

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
