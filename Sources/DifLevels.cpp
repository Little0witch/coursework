#include "../Headers/DifLevels.h"


DifLevels::DifLevels(sf::RenderWindow &other) : window(other) {

    if (!background.loadFromFile("../Resources/Img/Difficulty levels/difficultyLevels.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/DifLevels.cpp, line 8");
        exit(1);
    }
    if (!buttonEasyRed.loadFromFile("../Resources/Img/Difficulty levels/ButtonEasyRed.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/DifLevels.cpp, line 13");
        exit(1);
    }
    if (!buttonHardRed.loadFromFile("../Resources/Img/Difficulty levels/buttonHardRed.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/DifLevels.cpp, line 18");
        exit(1);
    }
    if (!buttonExitRed.loadFromFile("../Resources/Img/Difficulty levels/ButtonExitRed.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Headers/DifLevels.cpp, line 23");
        exit(1);
    }

    spriteBackground.setTexture(background);

    spriteButtonEasyRed.setTexture(buttonEasyRed);
    spriteButtonEasyRed.setPosition(570.f, 450.f);
    spriteButtonHardRed.setTexture(buttonHardRed);
    spriteButtonHardRed.setPosition(570.f, 623.f);
    spriteButtonExitRed.setTexture(buttonExitRed);
    spriteButtonExitRed.setPosition(570.f, 793.f);

}


void DifLevels::difLevelsRun()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            redEasy = false;
            redHard = false;
            redExit = false;
            if (event.type==sf::Event::Closed)
            {
                window.close();
                return;
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (spriteButtonEasyRed.getGlobalBounds().contains(mousePosition))
                {
                    redEasy = true;
                    redHard = false;
                    redExit = false;
                }
                else
                {
                    if (spriteButtonHardRed.getGlobalBounds().contains(mousePosition))
                    {
                        redEasy = false;
                        redHard = true;
                        redExit = false;
                    }
                    else
                    {
                        if (spriteButtonExitRed.getGlobalBounds().contains(mousePosition))
                        {
                            redEasy = false;
                            redHard = false;
                            redExit = true;
                        }
                    }
                }
            }
else
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=450 && event.mouseButton.y<=565))
                {
                    PlacementField placementField(window);
                    placementField.placementFieldRun(1, flag);
                    if (flag)
                    {
                        return;
                    }
                }
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=623 && event.mouseButton.y<=738))
                {
                    PlacementField placementField(window);
                    placementField.placementFieldRun(2, flag);
                    if (flag)
                    {
                        return;
                    }
                }
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=793 && event.mouseButton.y<=908))
                {
                    return;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        if (redEasy)
        {
            window.draw(spriteButtonEasyRed);
        }
        if (redHard)
        {
            window.draw(spriteButtonHardRed);
        }
        if (redExit)
        {
            window.draw(spriteButtonExitRed);
        }
        window.display();
    }
}

