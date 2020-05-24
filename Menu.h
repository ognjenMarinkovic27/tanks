#include <Windows.h>
#include<SFML/Graphics.hpp>

class Menu
{
    unsigned screenWidth, screenHeight, screen=1;
    sf::RenderWindow window;

    public:
        Menu(unsigned width, unsigned height);
        void run();


};
