#include <SFML/Graphics.hpp>
#include "GameMaster.h"
#include "Menu.h"

int main()
{
    GameMaster gm(1280, 720);
    Menu m(800, 600);
    m.run();
    gm.run();
}
