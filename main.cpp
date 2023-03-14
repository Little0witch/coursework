#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1846, 1048), "SFML works!");
    CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    Image image;
    image.loadFromFile("Resourses/p1.jpg");
    while (window.isOpen())
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
    }

    return 0;
}
