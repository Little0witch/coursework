#include "../Headers/netw_status.h"

netw_status::netw_status(sf::RenderWindow &other) : window(other) {

    background.loadFromFile("../Resources/Img/Network status/m_window_netw_status.png");
    sprite_background.setTexture(background);
    sprite_background.setPosition(590.f, 290.f);
    button_ok.loadFromFile("../Resources/Img/Network status/button_ok.png");
    sprite_button_ok.setTexture(button_ok);
    sprite_button_ok.setPosition(894.f, 540.f);
}

void netw_status::netw_status_run() {

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (sprite_button_ok.getGlobalBounds().contains(mouse_pos))
            {
                move_ok = true;
            }
            else
            {
                move_ok = false;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button ==sf::Mouse::Left)
            {
                if (sprite_button_ok.getGlobalBounds().contains(mouse_pos))
                {
                    return;
                }
            }
            window.draw(sprite_background);
            if (move_ok)
            {
                window.draw(sprite_button_ok);
            }
            window.display();
        }
        }

}


