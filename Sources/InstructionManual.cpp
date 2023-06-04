#include "../Headers/InstructionManual.h"

void InstructionManual::instructionManualRun()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            redExit = false;
            if (event.type==sf::Event::Closed)
            {
                window.close();
            }
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                if ((event.mouseButton.x>=665 && event.mouseButton.x<=1190) && (event.mouseButton.y>=918 && event.mouseButton.y<=1005))
                {
                    return;
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteExitRed.getGlobalBounds().contains(mousePosition))
                {
                    redExit = true;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        if (redExit)
        {
            window.draw(spriteExitRed);
        }
        window.display();
    }
}
