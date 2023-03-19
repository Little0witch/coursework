#include <SFML/Graphics.hpp>
#include "Headers/List.h"
#include "Headers/Array.h"
#include "Headers/Bot.h"


using namespace sf;

int main()
{

    //RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    //CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Yellow);

    //Image image;

    int** field = nullptr;

    field = allocateMemory(field,10,10);
    init(field,10,10);

    Bot bot;
    showArray(bot.getMyField(),10,10);

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
