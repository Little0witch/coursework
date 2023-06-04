#include "../Headers/NetwStatus.h"

NetwStatus::NetwStatus(sf::RenderWindow &other) : window(other) {
    if (!background.loadFromFile("../Resources/Img/Network status/windowNetwStatus.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Sources/NetwStatus.cpp, line 6");
        exit(1);
    }
    sprite_background.setTexture(background);
    sprite_background.setPosition(590.f, 290.f);
    if (!buttonOk.loadFromFile("../Resources/Img/Network status/buttonOk.png")) {
        logError(
                "Error 2: file opening error, the place where the error occurred: /Sources/NetwStatus.cpp, line 11");
        exit(1);
    }
    spriteButtonOk.setTexture(buttonOk);
    spriteButtonOk.setPosition(894.f, 540.f);
}

void NetwStatus::netwStatusRun() {

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
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (spriteButtonOk.getGlobalBounds().contains(mouse_pos))
            {
                moveOk = true;
            }
            else
            {
                moveOk = false;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button ==sf::Mouse::Left)
            {
                if (spriteButtonOk.getGlobalBounds().contains(mouse_pos))
                {
                    return;
                }
            }
            window.draw(sprite_background);
            if (moveOk)
            {
                window.draw(spriteButtonOk);
            }
            window.display();
        }
        }

}


