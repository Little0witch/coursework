#include <SFML/Graphics.hpp>
#include "Headers/ListOfCoord.h"
#include "Headers/Array.h"
#include "Headers/BotHard.h"
#include "Headers/ListOfShips.h"



using namespace sf;

int main()
{

    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    //CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Yellow);

    //Image image;

    ListOfCoord listCoord = nullptr;

    insertNode(&listCoord,0,0);
    insertNode(&listCoord,0,1);
    insertNode(&listCoord,0,2);

    ListOfShips listShips = nullptr;

    insertNode(&listShips,listCoord);

    printf("flag: %d\n", isHit(&listShips,0,0));
    printf("flag: %d\n", isHit(&listShips,0,1));
    printf("flag: %d\n", isHit(&listShips,0,2));

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
