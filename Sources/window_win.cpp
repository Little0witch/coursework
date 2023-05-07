#include "../Headers/window_win.h"

void window_win::window_win_run()
{
    sf::Vector2f mouse_position;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (sprite_ok_blue.getGlobalBounds().contains(mouse_position))
                {
                    window.draw(sprite_background);
                    window.draw(sprite_ok_red);
                    window.display();
                }
                else
                {
                    window.draw(sprite_background);
                    window.draw(sprite_ok_blue);
                    window.display();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if ((event.mouseButton.x>=700 && event.mouseButton.x<=1050) && (event.mouseButton.y>=570 && event.mouseButton.y<=820))
                {
                    return;
                }
            }

        }

    }
}
