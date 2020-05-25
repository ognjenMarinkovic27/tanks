#include <SFML/Graphics.hpp>
#include "GameMaster.h"
#include "Menu.h"

int main()
{
    GameMaster gm(1280, 720);
    Menu m(800, 600);
    m.run();
    int number;
    std::string name1, name2, name3, name4, name5;
    if(m.getOption() == 1)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        gm.run();
    }
    if(m.getOption() == 2)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
        gm.run();
    }
    if(m.getOption() == 3)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
        name4 = m.getName4();
        gm.run();
    }
    if(m.getOption() == 4)
    {
        number = m.getNumber();
        name1 = m.getName1();
        name2 = m.getName2();
        name3 = m.getName3();
        name4 = m.getName4();
        name5 = m.getName5();
        gm.run();
    }
}
