#include "../Headers/WindowWin.h"

void WindowWin::windowWinRun()
{
    sf::Vector2f mouse_position;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }

            if (event.type == sf::Event::MouseMoved)
            {
                mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteOkBlue.getGlobalBounds().contains(mouse_position))
                {
                    window.draw(spriteBackground);
                    window.draw(spriteOkRed);
                    window.display();
                }
                else
                {
                    window.draw(spriteBackground);
                    window.draw(spriteOkBlue);
                    window.display();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (spriteOkBlue.getGlobalBounds().contains(mouse_position))
                {
                    return;
                }
            }

        }

    }
}
