#include <SFML/Graphics.hpp>
#include "Headers/ListOfCoord.h"
#include "Headers/Array.h"
#include "Headers/BotHard.h"
#include "Headers/ListOfShips.h"
#include "Headers/BotSoft.h"



using namespace sf;

int main()
{

    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    //CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Yellow);

    //Image image;

    BotSoft botSoft;

    ListOfShips listShips = nullptr;

    listShips = botSoft.getListOfMyShips();

    //showList(listShips);


    /*while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    return 0;
}
