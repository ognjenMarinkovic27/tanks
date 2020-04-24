#include "GameMaster.h"

GameMaster::GameMaster(int width, int height) {
    gameWindow.create(sf::VideoMode(width, height), "Tanks", sf::Style::Close);
}


bool GameMaster::run() {
    while(gameWindow.isOpen()) {

        sf::Event evnt;
        while(gameWindow.pollEvent(evnt)) {
            if(evnt.type == evnt.Closed) {
                gameWindow.close();
            }
        }
    }
}
