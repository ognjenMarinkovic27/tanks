#include <windows.h>
#include <iostream>
#include "Menu.h"
#include "GameMaster.h"

sf::String playerInput1;
sf::Text playerText1;
sf::String playerInput2;
sf::Text playerText2;
sf::String playerInput3;
sf::Text playerText3;
sf::String playerInput4;
sf::Text playerText4;
sf::String playerInput5;
sf::Text playerText5;


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
            font.loadFromFile("fonts/Poppins-Regular.ttf");
            window.clear(sf::Color(50, 153, 255));

            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            sf::RectangleShape textbox1(sf::Vector2f(300.f, 50.f));
            textbox1.setPosition(screenWidth/2-150, screenHeight/3-25);
            if(pressed==1)
                textbox1.setFillColor(sf::Color(217, 217, 217));
            else
                textbox1.setFillColor(sf::Color(255, 255, 255));
            textbox1.setOutlineThickness(1.f);
            textbox1.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox1);
            playerText1.setFont(font);
            playerText1.setCharacterSize(30);
            playerText1.setFillColor(sf::Color(0, 0, 0));
            playerText1.setOutlineThickness(1.f);
            playerText1.setOutlineColor(sf::Color(0, 0, 0));
            playerText1.setPosition(screenWidth/2-140, screenHeight/3-20);

            sf::RectangleShape textbox2(sf::Vector2f(300.f, 50.f));
            textbox2.setPosition(screenWidth/2-150, screenHeight*2/3-25);
            if(pressed==2)
                textbox2.setFillColor(sf::Color(217, 217, 217));
            else
                textbox2.setFillColor(sf::Color(255, 255, 255));
            textbox2.setOutlineThickness(1.f);
            textbox2.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox2);
            playerText2.setFont(font);
            playerText2.setCharacterSize(30);
            playerText2.setFillColor(sf::Color(0, 0, 0));
            playerText2.setOutlineThickness(1.f);
            playerText2.setOutlineColor(sf::Color(0, 0, 0));
            playerText2.setPosition(screenWidth/2-140, screenHeight*2/3-20);

            sf::RectangleShape play(sf::Vector2f(100.f, 50.f));
            play.setPosition(screenWidth/2-50, 1);
            if(mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
                play.setFillColor(sf::Color(150, 0, 0));
            else
                play.setFillColor(sf::Color(204, 0, 0));
            play.setOutlineThickness(1.f);
            play.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(play);
            sf::Text playy;
            playy.setString("PLAY");
            playy.setFont(font);
            playy.setCharacterSize(30);
            playy.setFillColor(sf::Color(0, 0, 0));
            playy.setOutlineThickness(1.f);
            playy.setOutlineColor(sf::Color(0, 0, 0));
            playy.setPosition(screenWidth/2-33, 7);
            window.draw(playy);

            if(event.type == sf::Event::MouseButtonPressed && mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
            {
                option=1;
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed)
                pressed=0;

            if(event.type == sf::Event::MouseButtonPressed && mouseX > textbox1.getPosition().x && mouseX < textbox1.getPosition().x + 300 && mouseY > textbox1.getPosition().y && mouseY < textbox1.getPosition().y + 50)
                pressed=1;

            if(event.type == sf::Event::MouseButtonPressed && mouseX > textbox2.getPosition().x && mouseX < textbox2.getPosition().x + 300 && mouseY > textbox2.getPosition().y && mouseY < textbox2.getPosition().y + 50)
                pressed=2;


            if (event.type == sf::Event::TextEntered && pressed==1)
            {
                playerInput1 += (char)event.text.unicode;
                playerText1.setString(playerInput1);
            }

            if (event.type == sf::Event::TextEntered && pressed==2)
            {
                 playerInput2 += (char)event.text.unicode;
                 playerText2.setString(playerInput2);
            }


            window.draw(playerText1);
            window.draw(playerText2);
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

            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            sf::RectangleShape textbox1(sf::Vector2f(300.f, 50.f));
            textbox1.setPosition(screenWidth/2-150, screenHeight/4-25);
            if(pressed==1)
                textbox1.setFillColor(sf::Color(217, 217, 217));
            else
                textbox1.setFillColor(sf::Color(255, 255, 255));
            textbox1.setOutlineThickness(1.f);
            textbox1.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox1);
            playerText1.setFont(font);
            playerText1.setCharacterSize(30);
            playerText1.setFillColor(sf::Color(0, 0, 0));
            playerText1.setOutlineThickness(1.f);
            playerText1.setOutlineColor(sf::Color(0, 0, 0));
            playerText1.setPosition(screenWidth/2-140, screenHeight/4-20);

            sf::RectangleShape textbox2(sf::Vector2f(300.f, 50.f));
            textbox2.setPosition(screenWidth/2-150, screenHeight/2-25);
            if(pressed==2)
                textbox2.setFillColor(sf::Color(217, 217, 217));
            else
                textbox2.setFillColor(sf::Color(255, 255, 255));
            textbox2.setOutlineThickness(1.f);
            textbox2.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox2);
            playerText2.setFont(font);
            playerText2.setCharacterSize(30);
            playerText2.setFillColor(sf::Color(0, 0, 0));
            playerText2.setOutlineThickness(1.f);
            playerText2.setOutlineColor(sf::Color(0, 0, 0));
            playerText2.setPosition(screenWidth/2-140, screenHeight*1/2-20);

            sf::RectangleShape textbox3(sf::Vector2f(300.f, 50.f));
            textbox3.setPosition(screenWidth/2-150, screenHeight*3/4-25);
            if(pressed==3)
                textbox3.setFillColor(sf::Color(217, 217, 217));
            else
                textbox3.setFillColor(sf::Color(255, 255, 255));
            textbox3.setOutlineThickness(1.f);
            textbox3.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox3);
            playerText3.setFont(font);
            playerText3.setCharacterSize(30);
            playerText3.setFillColor(sf::Color(0, 0, 0));
            playerText3.setOutlineThickness(1.f);
            playerText3.setOutlineColor(sf::Color(0, 0, 0));
            playerText3.setPosition(screenWidth/2-140, screenHeight*3/4-20);

            sf::RectangleShape play(sf::Vector2f(100.f, 50.f));
            play.setPosition(screenWidth/2-50, 1);
            if(mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
                play.setFillColor(sf::Color(150, 0, 0));
            else
                play.setFillColor(sf::Color(204, 0, 0));
            play.setOutlineThickness(1.f);
            play.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(play);
            sf::Text playy;
            playy.setString("PLAY");
            playy.setFont(font);
            playy.setCharacterSize(30);
            playy.setFillColor(sf::Color(0, 0, 0));
            playy.setOutlineThickness(1.f);
            playy.setOutlineColor(sf::Color(0, 0, 0));
            playy.setPosition(screenWidth/2-33, 7);
            window.draw(playy);

            if(event.type == sf::Event::MouseButtonPressed && mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
            {
                option=2;
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed)
                pressed=0;

            if(event.type == sf::Event::MouseButtonPressed && mouseX > textbox1.getPosition().x && mouseX < textbox1.getPosition().x + 300 && mouseY > textbox1.getPosition().y && mouseY < textbox1.getPosition().y + 50)
                pressed=1;

            if(event.type == sf::Event::MouseButtonPressed && mouseX > textbox2.getPosition().x && mouseX < textbox2.getPosition().x + 300 && mouseY > textbox2.getPosition().y && mouseY < textbox2.getPosition().y + 50)
                pressed=2;

            if(event.type == sf::Event::MouseButtonPressed && mouseX > textbox3.getPosition().x && mouseX < textbox3.getPosition().x + 300 && mouseY > textbox3.getPosition().y && mouseY < textbox3.getPosition().y + 50)
                pressed=3;


            if (event.type == sf::Event::TextEntered && pressed==1)
            {
                playerInput1 += (char)event.text.unicode;
                playerText1.setString(playerInput1);
            }

            if (event.type == sf::Event::TextEntered && pressed==2)
            {
                 playerInput2 += (char)event.text.unicode;
                 playerText2.setString(playerInput2);
            }

            if(event.type == sf::Event::TextEntered && pressed==3)
            {
                 playerInput3 += (char)event.text.unicode;
                 playerText3.setString(playerInput3);
            }

            window.draw(playerText1);
            window.draw(playerText2);
            window.draw(playerText3);
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

            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            sf::RectangleShape textbox1(sf::Vector2f(300.f, 50.f));
            textbox1.setPosition(screenWidth/2-150, screenHeight/5-25);
            textbox1.setFillColor(sf::Color(255, 255, 255));
            textbox1.setOutlineThickness(1.f);
            textbox1.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox1);

            sf::RectangleShape textbox2(sf::Vector2f(300.f, 50.f));
            textbox2.setPosition(screenWidth/2-150, screenHeight*2/5-25);
            textbox2.setFillColor(sf::Color(255, 255, 255));
            textbox2.setOutlineThickness(1.f);
            textbox2.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox2);

            sf::RectangleShape textbox3(sf::Vector2f(300.f, 50.f));
            textbox3.setPosition(screenWidth/2-150, screenHeight*3/5-25);
            textbox3.setFillColor(sf::Color(255, 255, 255));
            textbox3.setOutlineThickness(1.f);
            textbox3.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox3);

            sf::RectangleShape textbox4(sf::Vector2f(300.f, 50.f));
            textbox4.setPosition(screenWidth/2-150, screenHeight*4/5-25);
            textbox4.setFillColor(sf::Color(255, 255, 255));
            textbox4.setOutlineThickness(1.f);
            textbox4.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox4);

            sf::RectangleShape play(sf::Vector2f(100.f, 50.f));
            play.setPosition(screenWidth/2-50, 1);
            if(mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
                play.setFillColor(sf::Color(150, 0, 0));
            else
                play.setFillColor(sf::Color(204, 0, 0));
            play.setOutlineThickness(1.f);
            play.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(play);
            sf::Text playy;
            playy.setString("PLAY");
            playy.setFont(font);
            playy.setCharacterSize(30);
            playy.setFillColor(sf::Color(0, 0, 0));
            playy.setOutlineThickness(1.f);
            playy.setOutlineColor(sf::Color(0, 0, 0));
            playy.setPosition(screenWidth/2-33, 7);
            window.draw(playy);

            if(event.type == sf::Event::MouseButtonPressed && mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
            {
                option=3;
                window.close();
            }

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

            int mouseX = sf::Mouse::getPosition(window).x;
            int mouseY = sf::Mouse::getPosition(window).y;

            sf::RectangleShape textbox1(sf::Vector2f(300.f, 50.f));
            textbox1.setPosition(screenWidth/2-150, screenHeight/6-25);
            textbox1.setFillColor(sf::Color(255, 255, 255));
            textbox1.setOutlineThickness(1.f);
            textbox1.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox1);

            sf::RectangleShape textbox2(sf::Vector2f(300.f, 50.f));
            textbox2.setPosition(screenWidth/2-150, screenHeight/3-25);
            textbox2.setFillColor(sf::Color(255, 255, 255));
            textbox2.setOutlineThickness(1.f);
            textbox2.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox2);

            sf::RectangleShape textbox3(sf::Vector2f(300.f, 50.f));
            textbox3.setPosition(screenWidth/2-150, screenHeight/2-25);
            textbox3.setFillColor(sf::Color(255, 255, 255));
            textbox3.setOutlineThickness(1.f);
            textbox3.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox3);

            sf::RectangleShape textbox4(sf::Vector2f(300.f, 50.f));
            textbox4.setPosition(screenWidth/2-150, screenHeight*2/3-25);
            textbox4.setFillColor(sf::Color(255, 255, 255));
            textbox4.setOutlineThickness(1.f);
            textbox4.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox4);

            sf::RectangleShape textbox5(sf::Vector2f(300.f, 50.f));
            textbox5.setPosition(screenWidth/2-150, screenHeight*5/6-25);
            textbox5.setFillColor(sf::Color(255, 255, 255));
            textbox5.setOutlineThickness(1.f);
            textbox5.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(textbox5);

            sf::RectangleShape play(sf::Vector2f(100.f, 50.f));
            play.setPosition(screenWidth/2-50, 1);
            if(mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
                play.setFillColor(sf::Color(150, 0, 0));
            else
                play.setFillColor(sf::Color(204, 0, 0));
            play.setOutlineThickness(1.f);
            play.setOutlineColor(sf::Color(0, 0, 0));
            window.draw(play);
            sf::Text playy;
            playy.setString("PLAY");
            playy.setFont(font);
            playy.setCharacterSize(30);
            playy.setFillColor(sf::Color(0, 0, 0));
            playy.setOutlineThickness(1.f);
            playy.setOutlineColor(sf::Color(0, 0, 0));
            playy.setPosition(screenWidth/2-33, 7);
            window.draw(playy);

            if(event.type == sf::Event::MouseButtonPressed && mouseX > play.getPosition().x && mouseX < play.getPosition().x + 100 && mouseY > play.getPosition().y && mouseY < play.getPosition().y + 50)
            {
                option=4;
                window.close();
            }

            window.display();
        }
    }
}

int Menu::getOption()
{
    return option;
}

int Menu::getNumber()
{
    return (option+1);
}

std::string Menu::getName1()
{
    return playerInput1;
}

std::string Menu::getName2()
{
    return playerInput2;
}

std::string Menu::getName3()
{
    return playerInput3;
}

std::string Menu::getName4()
{
    return playerInput4;
}

std::string Menu::getName5()
{
    return playerInput5;
}

