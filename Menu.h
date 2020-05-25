#include <Windows.h>
#include<SFML/Graphics.hpp>

class Menu
{
    unsigned screenWidth, screenHeight, screen=1, option=0, pressed=0;
    sf::RenderWindow window;
    std::string name1, name2, name3, name4, name5;

    public:
        Menu(unsigned width, unsigned height);
        void run();
        int getNumber();
        std::string getName1();
        std::string getName2();
        std::string getName3();
        std::string getName4();
        std::string getName5();
        int getOption();


};
