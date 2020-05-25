#include <SFML/Graphics.hpp>
#include "GameMaster.h"
#include "Menu.h"

int main()
{
    Menu m(800, 600);
    m.run();
    int number;
    std::string name1, name2, name3, name4, name5;
    int playerCount = m.getOption();
    if(playerCount == 1)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
    }
    if(playerCount == 2)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
    }
    if(playerCount == 3)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
        name4 = m.getName4();
    }
    if(playerCount == 4)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
        name4 = m.getName4();
        name5 = m.getName5();
    }
    std::string names[5] = {name1, name2, name3, name4, name5};
    GameMaster gm(1280, 720, playerCount+1, names);
    //m.run();
    gm.run();
}
