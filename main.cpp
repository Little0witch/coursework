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

    BotSoft botSoft1;
    BotSoft botSoft2;

    ListOfShips listOfShips1 = nullptr;
    ListOfShips listOfShips2 = nullptr;

    listOfShips1 = botSoft1.getListOfMyShips();
    listOfShips2 = botSoft2.getListOfMyShips();

    int** field1 = botSoft1.getMyField();
    int **field2 = botSoft2.getMyField();

    showArray(field1,10,10);
    printf("\n");
    showArray(field2,10,10);
    printf("\n");



    while (true)
    {





    }


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
