#include <windows.h>
#include <iostream>
#include "Menu.h"

Menu::Menu(unsigned width, unsigned height) {
    screenWidth = width;
    screenHeight = height;
}

void Menu::run()
{
    window.create(sf::VideoMode(screenWidth, screenHeight), "Tanks");
    while (window.isOpen() && screen==1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            sf::Font font;
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(0, 153, 255));

            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            sf::CircleShape button1(60.f);
            button1.setPointCount(100);
            button1.setPosition(screenWidth/5-60, screenHeight/2-30);
            if(mouseX > button1.getPosition().x && mouseX < button1.getPosition().x + 120 && mouseY > button1.getPosition().y && mouseY < button1.getPosition().y + 120)
                button1.setFillColor(sf::Color(150, 0, 0));
            else
                button1.setFillColor(sf::Color(204, 0, 0));
            button1.setOutlineThickness(1.f);
            button1.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(button1);
            sf::Text number1;
            number1.setFont(font);
            number1.setString("2");
            number1.setCharacterSize(60);
            number1.setFillColor(sf::Color(0, 0, 0));
            number1.setPosition(screenWidth/5-20, screenHeight/2-10);
            window.draw(number1);


            sf::CircleShape button2(60.f);
            button2.setPointCount(100);
            button2.setPosition(screenWidth*2/5-60, screenHeight/2-30);
            if(mouseX > button2.getPosition().x && mouseX < button2.getPosition().x + 120 && mouseY > button2.getPosition().y && mouseY < button2.getPosition().y + 120)
                button2.setFillColor(sf::Color(150, 0, 0));
            else
                button2.setFillColor(sf::Color(204, 0, 0));
            button2.setOutlineThickness(1.f);
            button2.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(button2);
            sf::Text number2;
            number2.setFont(font);
            number2.setString("3");
            number2.setCharacterSize(60);
            number2.setFillColor(sf::Color(0, 0, 0));
            number2.setPosition(screenWidth*2/5-20, screenHeight/2-10);
            window.draw(number2);

            sf::CircleShape button3(60);
            button3.setPointCount(100);
            button3.setPosition(screenWidth*3/5-60, screenHeight/2-30);
            if(mouseX > button3.getPosition().x && mouseX < button3.getPosition().x + 120 && mouseY > button3.getPosition().y && mouseY < button3.getPosition().y + 120)
                button3.setFillColor(sf::Color(150, 0, 0));
            else
                button3.setFillColor(sf::Color(204, 0, 0));
            button3.setOutlineThickness(1.f);
            button3.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(button3);
            sf::Text number3;
            number3.setFont(font);
            number3.setString("4");
            number3.setCharacterSize(60);
            number3.setFillColor(sf::Color(0, 0, 0));
            number3.setPosition(screenWidth*3/5-20, screenHeight/2-10);
            window.draw(number3);

            sf::CircleShape button4(60);
            button4.setPointCount(100);
            button4.setPosition(screenWidth*4/5-60, screenHeight/2-30);
            if(mouseX > button4.getPosition().x && mouseX < button4.getPosition().x + 120 && mouseY > button4.getPosition().y && mouseY < button4.getPosition().y + 120)
                button4.setFillColor(sf::Color(150, 0, 0));
            else
                button4.setFillColor(sf::Color(204, 0, 0));
            button4.setOutlineThickness(1.f);
            button4.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(button4);
            sf::Text number4;
            number4.setFont(font);
            number4.setString("5");
            number4.setCharacterSize(60);
            number4.setFillColor(sf::Color(0, 0, 0));
            number4.setPosition(screenWidth*4/5-20, screenHeight/2-10);
            window.draw(number4);

            sf::Text text;
            text.setFont(font);
            text.setString("Number of players");
            text.setCharacterSize(80);
            text.setFillColor(sf::Color(204, 0, 0));
            text.setOutlineThickness(1.f);
            text.setOutlineColor(sf::Color(0, 0, 0));
            text.setPosition(30, 100);
            window.draw(text);

            if (event.type == sf::Event::MouseButtonPressed && mouseX > button1.getPosition().x && mouseX < button1.getPosition().x + 120 && mouseY > button1.getPosition().y && mouseY < button1.getPosition().y + 120)
                screen=2;
            if (event.type == sf::Event::MouseButtonPressed && mouseX > button2.getPosition().x && mouseX < button2.getPosition().x + 120 && mouseY > button2.getPosition().y && mouseY < button2.getPosition().y + 120)
                screen=3;
            if (event.type == sf::Event::MouseButtonPressed && mouseX > button3.getPosition().x && mouseX < button3.getPosition().x + 120 && mouseY > button3.getPosition().y && mouseY < button3.getPosition().y + 120)
                screen=4;
            if (event.type == sf::Event::MouseButtonPressed && mouseX > button4.getPosition().x && mouseX < button4.getPosition().x + 120 && mouseY > button4.getPosition().y && mouseY < button4.getPosition().y + 120)
                screen=5;

            window.display();
        }
    }

    while (window.isOpen() && screen==2)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            sf::Font font;
            sf::String playerInput;
            sf::Text playerText;
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(0, 153, 255));

            if (event.type == sf::Event::TextEntered)
            {
                playerInput +=event.text.unicode;
                playerText.setString(playerInput);
            }

            playerText.setFont(font);
            playerText.setCharacterSize(80);
            playerText.setFillColor(sf::Color(204, 0, 0));
            playerText.setOutlineThickness(1.f);
            playerText.setOutlineColor(sf::Color(0, 0, 0));
            playerText.setPosition(30, 100);
            window.draw(playerText);

            window.display();
        }
    }

    while (window.isOpen() && screen==3)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            sf::Font font;
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(0, 253, 255));

            window.display();
        }
    }

    while (window.isOpen() && screen==4)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            sf::Font font;
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(0, 0, 255));

            window.display();
        }
    }

    while (window.isOpen() && screen==5)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            sf::Font font;
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(0, 153, 115));

            window.display();
        }
    }
}
