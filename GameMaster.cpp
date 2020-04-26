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
/*bool oneclick = true;
int k=0;*/
void GameMaster::run() {
    gameWindow.create(sf::VideoMode(screenWidth, screenHeight), "Tanks", sf::Style::Close | sf::Style::Resize);
    std::vector<int> heightMap = tg.getHeightMap();

    sf::Font font;
    font.loadFromFile("fonts/Poppins-Regular.ttf");

    std::string names[playerCount] = {"Ognjen", "Pajdan", "Vasilije", "Cigan"};


    for(int i=0;i<playerCount;i++)
    {
        Player p(names[i%(playerCount-1)], sf::Color(rand()%256, rand()%256, rand()%256));
        players.push_back(p);
        int X = screenWidth/(playerCount+1)*(i+1);
        Rigidbody* rb = new Rigidbody(X, heightMap[X]);
        pe.addRigidbody(rb);

    }

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




        bool** terrain = tg.getTerrain();
        heightMap = tg.getHeightMap();





        /*sf::RectangleShape objectSprite(sf::Vector2f(30, 15));
        objectSprite.setOrigin(15.0f, 7.5f);
        objectSprite.setFillColor(sf::Color::Red);
        objectSprite.setPosition(sf::Vector2f(object.getPosition().x, screenHeight-(1+(object.getPosition().y))));
        objectSprite.setRotation(object.getRotation()-90);

        sf::RectangleShape line(sf::Vector2f(1280,4));
        line.setPosition(sf::Vector2f(object.getPosition().x, screenHeight-(1+(object.getPosition().y))));
        line.setRotation(object.getRotation()+90);
        line.setFillColor(sf::Color::Magenta);*/


        /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);
            sf::RectangleShape cursor(sf::Vector2f(30, 30));
            cursor.setOrigin(15.0f, 15.0f);
            cursor.setFillColor(sf::Color::Cyan);
            cursor.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
            gameWindow.draw(cursor);
            if(oneclick) {
                for(int i=mousePos.x-30;i<=mousePos.x+30;i++) {
                    tg.destroyTerrain(i,60);
                    for(int j=mousePos.y-30;j<=mousePos.y+30;j++) {

                        terrain[i][(screenHeight-j-1)] = 0;
                        oneclick = false;
                    }

                }
                heightMap=tg.getHeightMap();
                k=1;
            }

        }*/

        pe.simulate(terrain, heightMap, screenWidth, screenHeight);

        gameWindow.clear();
        drawTerrain();
        std::vector<Rigidbody*> rigidbodies = pe.getRigidbodies();
        for(int i=0;i<playerCount;i++) {
            float X = rigidbodies[i]->getPosition().x;
            float Y = screenHeight-(1+rigidbodies[i]->getPosition().y);
            sf::Text name(players[i].getName(), font, 12);
            name.setColor(players[i].getColor());
            name.setOutlineColor(sf::Color::Black);
            name.setPosition(X-15,Y+20);
            name.setOutlineThickness(1);
            name.setLetterSpacing(2);
            sf::RectangleShape objectSprite(sf::Vector2f(30, 15));
            objectSprite.setOrigin(15.0f, 7.5f);
            objectSprite.setFillColor(players[i].getColor());
            objectSprite.setPosition(sf::Vector2f(X,Y));
            objectSprite.setRotation(rigidbodies[i]->getRotation()-90);
            gameWindow.draw(objectSprite);
            gameWindow.draw(name);
        }



        /*for(int i=0;i<heightMap.size();i++) {
            sf::RectangleShape square(sf::Vector2f(5,5));
            square.setFillColor(sf::Color::Black);
            square.setOrigin(2.5,2.5);
            square.setPosition(i, screenHeight-heightMap[i]-1);
            gameWindow.draw(square);
        }*/

        /*gameWindow.draw(objectSprite);
        gameWindow.draw(line);*/

        gameWindow.display();
    }
}

void GameMaster::drawTerrain() {
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
}
