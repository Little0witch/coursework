#include "../Headers/MainMenu.h"

void MainMenu::mainMenuRun()
{
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            redOnline = false;
            redDifLv= false;
            redMan = false;
            redExit = false;
            if (event.type==sf::Event::Closed)
            {
                window.close();
                return;
            }
        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
            {
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=340 && event.mouseButton.y<=455))
                {
                    ConnectType windowConnectType(window);
                    windowConnectType.connectTypeRun();
                }else
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=513 && event.mouseButton.y<=628))
                {
                    DifLevels windowLevels(window);
                    windowLevels.difLevelsRun();
                }
                else
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=685 && event.mouseButton.y<=800))
                {
                    InstructionManual windowInstruction(window);
                    windowInstruction.instructionManualRun();
                }else
                if ((event.mouseButton.x>=570 && event.mouseButton.x<=1261) && (event.mouseButton.y>=857 && event.mouseButton.y<=972))
                {
                    window.close();
                    return;
                }
            }
else
            if (event.type == sf::Event::MouseMoved)
            {
                if (spriteOnlinePlay.getGlobalBounds().contains(mouse_pos))
                {
                    redOnline = true;
                    redDifLv= false;
                    redMan = false;
                    redExit = false;
                }
                else
                {
                    if (spriteButtonLevels.getGlobalBounds().contains(mouse_pos)) {
                        redOnline = false;
                        redDifLv = true;
                        redMan= false;
                        redExit = false;
                    } else
                    {
                        if (spriteInstructionManual.getGlobalBounds().contains(mouse_pos)) {
                            redOnline = false;
                            redDifLv = false;
                            redMan = true;
                            redExit = false;
                        } else {
                            if (spriteExit.getGlobalBounds().contains(mouse_pos)) {
                                redOnline = false;
                                redDifLv = false;
                                redMan = false;
                                redExit = true;
                            }
                        }
                    }
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(spriteBackground);
        if(redOnline)
        {
            window.draw(spriteOnlinePlay);
        }
        if (redDifLv)
        {
            window.draw(spriteButtonLevels);
        }
        if (redMan)
        {
            window.draw(spriteInstructionManual);
        }
        if (redExit)
        {
            window.draw(spriteExit);
        }
        window.display();
    }
}