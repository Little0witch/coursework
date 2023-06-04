#include "../Headers/WindowExit.h"

void WindowExit::windowExitRun(bool &flag)
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            redNo = false;
            redYes = false;
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteYesRed.getGlobalBounds().contains(mousePosition))
                {
                    redYes = true;
                    redNo = false;
                }
                else
                {
                    if (spriteNoRed.getGlobalBounds().contains(mousePosition))
                    {
                        redNo = true;
                        redYes = false;
                    }
                }
            }

            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteYesRed.getGlobalBounds().contains(mouse_pos))
                {
                    flag = true;
                    return;
                }
                if (spriteNoRed.getGlobalBounds().contains(mouse_pos))
                {
                    flag = false;
                    return;
                }
            }
        }
        window.draw(spriteBackground);
        if (redYes)
        {
            window.draw(spriteYesRed);
        }
        if (redNo)
        {
            window.draw(spriteNoRed);
        }
        window.display();
    }
}
