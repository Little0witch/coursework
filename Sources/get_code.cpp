#include "../Headers/get_code.h"

void get_code::get_code_run() {

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (sprite_ok_red.getGlobalBounds().contains(mouse_pos))
                {
                    return;
                }
            }
            if (sprite_ok_red.getGlobalBounds().contains(mouse_pos))
            {
                move_on_button = true;
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite_background);
        window.draw(connect_code);
        if (move_on_button)
        {
            window.draw(sprite_ok_red);
        }
        window.display();
    }

}
