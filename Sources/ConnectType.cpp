#include "../Headers/ConnectType.h"

ConnectType::ConnectType(sf::RenderWindow &other) : window(other) {

        if (!background.loadFromFile("../Resources/Img/Type connect/wConnectType.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/ConnectType.cpp, line 7");
            exit(1);
        }

        spriteBackground.setTexture(background);

        if (!buttonClient.loadFromFile("../Resources/Img/Type connect/buttonClient.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/ConnectType.cpp, line 15");
            exit(1);
        }

        spriteButtonClient.setTexture(buttonClient);
        spriteButtonClient.setPosition(sf::Vector2f(573.f, 280.f));

        if (!buttonServer.loadFromFile("../Resources/Img/Type connect/buttonServer.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/ConnectType.cpp, line 24");
            exit(1);
        }

        spriteButtonServer.setTexture(buttonServer);
        spriteButtonServer.setPosition(sf::Vector2f(573.f, 450.f));

        if (!buttonExit.loadFromFile("../Resources/Img/Type connect/buttonExit.png")) {
            logError(
                    "Error 2: file opening error, the place where the error occurred: /Headers/ConnectType.cpp, line 533");
            exit(1);
        }

        spriteButtonExit.setTexture(buttonExit);
        spriteButtonExit.setPosition(sf::Vector2f(573.f, 620.f));
}


void ConnectType::connectTypeRun() {

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            flagOfReturn = false;
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }

            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=280 && event.mouseMove.y<=405)
            {
                moveClient = true;
            }
            else
            {
                moveClient = false;
            }
            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=450 && event.mouseMove.y<=575)
            {
                moveServer = true;
            }
            else
            {
                moveServer = false;
            }
            if (event.mouseMove.x>=573 && event.mouseMove.x<=1273 && event.mouseMove.y>=620 && event.mouseMove.y<=745)
            {
                moveExit = true;
            }
            else
            {
                moveExit = false;
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=280 && event.mouseButton.y<=405)
                {
                    InputCode windowInputCode(window);
                    windowInputCode.inputCodeRun(flagOfReturn);
                    return;
                }
                else
                {
                    if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=450 && event.mouseButton.y<=575)
                    {
                        GetCode windowGetCode(window);
                        windowGetCode.getCodeRun(flagOfReturn);
                        return;
                    }
                    else
                    {
                        if (event.mouseButton.x>=573 && event.mouseButton.x<=1273 && event.mouseButton.y>=620 && event.mouseButton.y<=745)
                        {
                            return;
                        }
                    }

                }
            }

            window.draw(spriteBackground);
            if (moveClient)
            {
                window.draw(spriteButtonClient);
            }
            if (moveServer)
            {
                window.draw(spriteButtonServer);
            }
            if (moveExit)
            {
                window.draw(spriteButtonExit);
            }
            window.display();
        }
    }
}
