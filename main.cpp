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

    //BotSoft botSoft;
    ListOfShips listShips = nullptr;
    ListOfCoord listCoord = nullptr;

    //listShips = botSoft.getListOfMyShips();

    insertNode(&listCoord,0,1);
    insertNode(&listCoord,0,2);
    insertNode(&listCoord,0,3);

    insertNode(&listShips,listCoord);

    freeList(&listCoord);

    insertNode(&listCoord,1,1);
    insertNode(&listCoord,1,2);

    insertNode(&listShips,listCoord);

    showList(listShips);

    isHit(listShips,1,1);
    isHit(listShips,0,1);
    isHit(listShips,0,2);
    isHit(listShips,0,2);
    isHit(listShips,0,2);


    showList(listShips);

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
